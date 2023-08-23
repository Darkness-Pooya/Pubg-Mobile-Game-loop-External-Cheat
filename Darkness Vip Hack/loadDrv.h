#pragma once
#include "Includes.h"
#include "Algorithm\Algorithm.h"
#include "Settings\Settings.h"
#include "Data\Data.h"
#include ".\Dx11\DX11.h"

class DRIVER {

	bool WriteDataToFile(const UCHAR pBuffer[], const DWORD dwSize, const std::string& strFileName, const DWORD dwCreationDisposition = CREATE_NEW)
	{
		const auto hFile = CreateFileA(strFileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, nullptr);
		if (hFile == INVALID_HANDLE_VALUE) return false;
		DWORD dwNumberOfBytesWritten = NULL;
		const auto bWriteFile = WriteFile(hFile, pBuffer, dwSize, &dwNumberOfBytesWritten, nullptr);
		CloseHandle(hFile);
		return !(!bWriteFile || dwNumberOfBytesWritten != dwSize);
	}

public:
	DRIVER(const std::string& strDriverFile,
		const std::string& strDeviceName,
		const std::string& strDriverName,
		const unsigned char* pRawDriver = nullptr,
		const size_t szRawDriver = 0)
	{
		// Using either absolute path or getting relative path
		m_strDriverFile = strDriverFile;
		if (strDriverFile.find_first_of(':') == std::string::npos)
		{
			char currentPath[MAX_PATH];
			GetCurrentDirectoryA(MAX_PATH, currentPath);
			std::string strCurrentPath = currentPath;
			strCurrentPath += "\\";
			m_strDriverFile = strCurrentPath + strDriverFile;
		}

		m_strDeviceName = strDeviceName;
		m_strDriverName = strDriverName;
		m_pRawDriver = pRawDriver;
		m_szRawDriver = szRawDriver;

		Load();
	}
	bool removeAllOnExit = false;

	bool Unload()
	{
		// Closing handle

		// If we want to forcibly stop the driver's service and uninstall it, we ignore if it was running and installed
		if (removeAllOnExit)
		{
			m_wasRunning = false;
			m_wasInstalled = false;
		}

		// If the service was running we just leave it be just as it was
		if (m_wasRunning && !removeAllOnExit)
			return true;

		// Getting ready to interact with the service to stop, disable, and/or delete it
		SERVICE_STATUS scStatus;
		const auto hScm = OpenSCManagerA(nullptr, nullptr, SC_MANAGER_CONNECT);
		if (!hScm)
			return false;
		DWORD dwServicePermission = SERVICE_STOP;
		if (!m_wasInstalled)
			dwServicePermission |= DELETE;
		if (m_wasDisabled)
			dwServicePermission |= SERVICE_CHANGE_CONFIG;
		const auto hSc = OpenServiceA(hScm, m_strDriverName.c_str(), dwServicePermission);
		if (!hSc)
		{
			CloseServiceHandle(hScm);
			return false;
		}

		// If the service was not running we stop it
		if (!ControlService(hSc, SERVICE_CONTROL_STOP, &scStatus))
		{
			CloseServiceHandle(hSc);
			CloseServiceHandle(hScm);
			return false;
		}

		// If the service was disabled we re-disable it
		if (m_wasDisabled)
			if (!ChangeServiceConfigA(hSc, SERVICE_NO_CHANGE, SERVICE_DISABLED, SERVICE_NO_CHANGE, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr))
			{
				CloseServiceHandle(hSc);
				CloseServiceHandle(hScm);
				return false;
			}

		// If the service was installed we stop here
		if (m_wasInstalled && !removeAllOnExit)
		{
			CloseServiceHandle(hSc);
			CloseServiceHandle(hScm);
			return true;
		}

		// If the service was not installed, we uninstall it
		const auto bDeleteService = DeleteService(hSc);
		CloseServiceHandle(hSc);
		CloseServiceHandle(hScm);

		// If we should delete the file we delete it
		if (m_fileWasCreated && removeAllOnExit)
			return DeleteFileA(m_strDriverFile.c_str());

		return bDeleteService;
	}


	bool Load()
	{
		// Try to get a handle on the driver (if already loaded)
		m_wasRunning = false;

		// Getting ready to interact with the service
		const auto hScm = OpenSCManagerA(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);
		if (!hScm)
			return false;

		// Trying to get a handle on the service if it exist, otherwise we create it
		auto hSc = OpenServiceA(hScm, m_strDriverName.c_str(), SERVICE_START);
		if (!hSc)
		{
			// If driver file doesn't exist on disk and we have an embedded driver, we write it on disk
			if (WriteDataToFile(m_pRawDriver, m_szRawDriver, m_strDriverFile))
				m_fileWasCreated = true;
			else
				m_fileWasCreated = false;

			hSc = CreateServiceA(hScm, m_strDriverName.c_str(), "", SERVICE_START, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, m_strDriverFile.c_str(), nullptr, nullptr, nullptr, nullptr, nullptr);
			if (!hSc)
			{
				// Service doesn't exist and can't create it, aborting
				CloseServiceHandle(hScm);
				return false;
			}
			m_wasInstalled = false;
		}
		else
			m_wasInstalled = true; // The service was already installed

		// Starting service
		auto bStartService = StartServiceA(hSc, NULL, nullptr);
		if (!bStartService && GetLastError() == ERROR_SERVICE_DISABLED)
		{
			// Couldn't start service because it is disabled, upgrading handle to modify servcie configuration and starting it
			CloseServiceHandle(hSc);
			hSc = OpenServiceA(hScm, m_strDriverName.c_str(), SERVICE_START | SERVICE_CHANGE_CONFIG);
			const auto bChangeServiceConfig = ChangeServiceConfigA(hSc, SERVICE_NO_CHANGE, SERVICE_DEMAND_START, SERVICE_NO_CHANGE, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
			std::cout << "GLE = " << std::dec << GetLastError() << std::endl;
			if (bChangeServiceConfig)
			{
				bStartService = StartServiceA(hSc, NULL, nullptr);
				if (bStartService)
					m_wasDisabled = true;
				else
					m_wasDisabled = false;
			}
		}
		CloseServiceHandle(hSc);
		CloseServiceHandle(hScm);

		// Getting handle
		return true;
	}

	std::string m_strDriverFile = "";
	std::string m_strDeviceName = "";
	std::string m_strDriverName = "";

	const unsigned char* m_pRawDriver = nullptr;
	size_t m_szRawDriver = 0;

	bool m_wasRunning = false;
	bool m_wasInstalled = false;
	bool m_wasDisabled = false;
	bool m_fileWasCreated = false;

	HANDLE m_hDriver = nullptr;
};