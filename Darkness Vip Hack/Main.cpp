#include "Includes.h"
#include ".\Utility\Utility.h"
#include ".\Esp\Esp.h"
#include "Driver.h"
#include ".\Settings\Settings.h"
#include ".\icon.h"
#include ".\Data\Data.h"
#include ".\Aimbot\Aimbot.h"
#include ".\Memory.h"
#include ".\resource.h"
#define XTREME_DRIVER_FILE  "Darkness.sys"
#define XTREME_SERVICE_NAME "Darkness"
#define XTREME_DEVICE_NAME  "\\Device\\Darkness"
DRIVER* m_drv = nullptr;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	char Buffer[1000];
	GetClassNameA(hWnd, Buffer, 1000);

	string WindowClassName = Buffer;
	if (Emulator::IsSmartGaGa == TRUE)
	{
		if (WindowClassName.find("TitanRenderWindowClass") != string::npos)
		{
			wchar_t Name[1000];
			GetWindowTextW(hWnd, Name, 1000);
			Game::hWindow = FindWindowW(L"TitanRenderWindowClass", Name);
		}
	}
	else if (Emulator::IsGameLoop == TRUE)
	{
		if (WindowClassName.find("TXGuiFoundation") != string::npos)
		{
			wchar_t Name[1000];
			GetWindowTextW(hWnd, Name, 1000);
			Game::hWindow = FindWindowW(L"TXGuiFoundation", Name);
		}
	}
	else if (Emulator::IsGameLoop7 == TRUE)
	{
		if (WindowClassName.find("TXGuiFoundation") != string::npos)
		{
			wchar_t Name[1000];
			GetWindowTextW(hWnd, Name, 1000);
			Game::hWindow = FindWindowW(L"TXGuiFoundation", Name);
			if (!Game::hWindow)
			{
				Game::hWindow = FindWindowEx(NULL, NULL, "TXGuiFoundation", "Gameloop【Turbo AOW Engine-7.1 Beta】");
			}

		}
	}
	return TRUE;
	//return 0;
}
void RunStyle()
{
	ImGuiStyle& style1 = ImGui::GetStyle();
	auto colors = style1.Colors; // ImColor = RBG & A = 250
	colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0);
	colors[ImGuiCol_TitleBg] = ImColor(110, 108, 111);
	//colors[ImGuiCol_TitleBgActive] = ImColor(134, 3, 255); // Upar Border Color 
	colors[ImGuiCol_TitleBgActive] = ImColor(254, 0, 0); // Upar Border Color 

	colors[ImGuiCol_TitleBgCollapsed] = ImColor(8, 2, 38);

	colors[ImGuiCol_FrameBg] = ImColor(8, 2, 50);
	colors[ImGuiCol_FrameBgActive] = ImColor(8, 2, 90);  //////// 82, 31, 37
	colors[ImGuiCol_FrameBgHovered] = ImColor(8, 2, 70); //154, 38, 54

	colors[ImGuiCol_Separator] = ImColor(0, 255, 251);   // 88  29 31
	colors[ImGuiCol_SliderGrab] = ImColor(121, 255, 248);
	colors[ImGuiCol_SliderGrabActive] = ImColor(237, 121, 255);   ///// 61, 129, 221

	colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0);//ed
	colors[ImGuiCol_PopupBg] = ImColor(20, 22, 24);//ed
	colors[ImGuiCol_ScrollbarBg] = ImColor(20, 22, 24);
	//colors[ImGuiCol_ScrollbarGrab] = ImColor(12, 146, 10);
	//colors[ImGuiCol_ScrollbarGrabActive] = ImColor(12, 146, 10);   154, 38, 54
	//colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(12, 146, 15);
	colors[ImGuiCol_Border] = ImColor(70, 70, 70);
	colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0);
	colors[ImGuiCol_Header] = ImColor(2, 255, 247/*17, 25, 67*/);  // 154  38  54
	colors[ImGuiCol_HeaderHovered] = ImColor(130, 2, 255);  //  233, 51, 56
	colors[ImGuiCol_HeaderActive] = ImColor(197, 60, 254);
	colors[ImGuiCol_Button] = ImColor(255, 0, 0); // 82, 31, 37          130, 2, 255
	colors[ImGuiCol_ButtonHovered] = ImColor(0, 255, 58); // ImColor(4, 204, 255)
	colors[ImGuiCol_ButtonActive] = ImColor(255, 0, 58); //// 82, 31, 37
	colors[ImGuiCol_Text] = ImColor(255, 255, 255);
	colors[ImGuiCol_CheckMark] = ImColor(21, 243, 221);
	/* colors[ImGuiCol_CheckMark] = ImColor(237, 121, 255);*/// 154, 38, 54
	//style1.WindowMinSize = ImVec2(300, 300);
	style1.WindowPadding = ImVec2(6, 6);
	style1.FramePadding = ImVec2(4, 4);
	style1.ItemSpacing = ImVec2(12, 12);
	style1.WindowTitleAlign.x = 0.50f;     //////////////// 0.043f;
	style1.FrameRounding = 7; // 2;
	style1.GrabRounding = 2.0f;
	style1.WindowRounding = 10;
	style1.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}
void WriteResToDisk(std::string PathFile, LPCSTR File_WITHARG)
{
	HRSRC myResource = ::FindResource(NULL, File_WITHARG, RT_RCDATA);
	unsigned int myResourceSize = ::SizeofResource(NULL, myResource);
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyExecutable = ::LockResource(myResourceData);
	std::ofstream f(PathFile, std::ios::out | std::ios::binary);
	f.write((char*)pMyExecutable, myResourceSize);
	f.close();
}

int main() {
	FreeConsole();
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
	int scrWidth = GetSystemMetrics(SM_CXSCREEN);
	int scrHeight = GetSystemMetrics(SM_CYSCREEN);

	WriteResToDisk("C:\\Darkness.sys", (LPCSTR)MAKEINTRESOURCE(DriverDarkness));
	WriteResToDisk("C:\\X.ttf", (LPCSTR)MAKEINTRESOURCE(FontDarkness));
	//system(("sc create DARKNESSHck binPath=\"C:\\Darkness.sys\" type=filesys"));
	//system(("sc start DARKNESSHck"));

	m_drv = new DRIVER(XTREME_DRIVER_FILE, XTREME_DEVICE_NAME, XTREME_SERVICE_NAME, Driver, DriverSize);
	m_drv->Load();
	TCHAR procid[256] = "aow_exe.exe";
	TCHAR procidss[256] = "AndroidProcess.exe";
	Game::Id = Utility::GetTrueProcessId(procidss);
	if (Game::Id > 0)
	{
		Emulator::IsSmartGaGa = TRUE;
	}
	else
	{
		Game::Id = Utility::GetTrueProcessId(procid);
		if (Game::Id > 0)
		{
			Emulator::IsGameLoop = TRUE;
		}
	}

	if (Game::Id == 0)
	{
		//	Driver::UnloadDriver(DriverName.c_str());
		MessageBox(NULL, "Can't Find Game Id", "Darkness", MB_OKCANCEL);
		system("pause >nul");
		ExitProcess(0);
	}

	Game::hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Game::Id);

	if (Game::hProcess == 0)
	{
		//Driver::UnloadDriver(DriverName.c_str());
		MessageBox(NULL, "Can't Find Game Process", "Darkness", MB_OKCANCEL);
		system("pause >nul");
		ExitProcess(0);
	}
	if (Emulator::IsSmartGaGa == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"TitanRenderWindowClass", L"SmartGaGa RenderWindow");
		Game::hWindow = FindWindowEx(FindWindow(0, "TitanRenderWindowClass"), NULL,"TitanRenderWindowClass", "SmartGaGa RenderWindow");

	}

	else if (Emulator::IsGameLoop == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
	}
	if (Game::hWindow == 0)
	{
		//m_drv->Unload();
		MessageBox(NULL,"Can't Find Game Window", "Darkness", MB_OKCANCEL);
		system("pause >nul");
		ExitProcess(0);
	}

	if (Emulator::IsSmartGaGa == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"TitanRenderWindowClass", L"SmartGaGa RenderWindow");
		Game::hWindow = FindWindowEx(FindWindow(0, "TitanRenderWindowClass"), NULL, "TitanRenderWindowClass", "SmartGaGa RenderWindow");

	}

	else if (Emulator::IsGameLoop == true)
	{
		EnumWindows(EnumWindowsProc, 0);
		if (IsIconic(Game::hWindow) != 0) ShowWindow(Game::hWindow, SW_RESTORE);
		Game::hWindow = FindWindowExW(Game::hWindow, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
	}

	if (Game::hWindow == 0)
	{
		HWND WindowParent = FindWindow(0, "DARKNESS");
		Game::hWindow = FindWindowExW(WindowParent, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
		if (Game::hWindow == 0)
		{
			HWND WindowParent = FindWindow(0, "GameLoop");
			Game::hWindow = FindWindowExW(WindowParent, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
			if (Game::hWindow == 0)
			{
				HWND WindowParent = FindWindow(0, "Gameloop");
				Game::hWindow = FindWindowExW(WindowParent, 0, L"AEngineRenderWindowClass", L"AEngineRenderWindow");
				if (Game::hWindow == 0)
				{
					m_drv->Unload();
					MessageBox(NULL, "Can't Find Game Window", "DARKNESS", MB_OKCANCEL);
					system("pause >nul");
					ExitProcess(0);
				}
			}
		}
	}
	int scrWidthh = GetSystemMetrics(SM_CXSCREEN);
	int scrHeightt = GetSystemMetrics(SM_CYSCREEN);
	RECT Rect;
	GetWindowRect(Game::hWindow, &Rect);
	if (Rect.left < 0 || Rect.top < 0 || Rect.right < 0 || Rect.bottom < 0)
	{

		RECT tSize;
		GetWindowRect(Game::hWindow, &tSize);
		scrWidthh = tSize.right - tSize.left;
		scrHeightt = tSize.bottom - tSize.top;

		SetWindowPos(DX11Window::hWindow, HWND_TOPMOST, tSize.left, tSize.top, scrWidthh, scrHeightt, SWP_NOMOVE | SWP_NOSIZE);
	}
	if (Emulator::IsSmartGaGa == true)
	{

		Data::ViewMatrixBase = Data::GetViewMatrixBase(0x70000000, 0x90000000);

		if (Data::ViewMatrixBase == 0)
		{
			Data::ViewMatrixBase = Data::GetViewMatrixBase(0x90000000, 0xA0000000);
			Emulator::IsSmartGaGa4 = true;
		}
		else
		{
			Emulator::IsSmartGaGa7 = true;
		}
	}
	else if (Emulator::IsGameLoop == true)
	{

		Data::ViewMatrixBase = Data::GetViewMatrixBase(0x45000000, 0x65000000);

		if (Data::ViewMatrixBase == 0)
		{
			Data::ViewMatrixBase = Data::GetViewMatrixBase(0x25000000, 0x35000000);
			Emulator::IsGameLoop4 = true;
		}
		else
		{
			Emulator::IsGameLoop7 = true;
		}
	}

	//if (Data::ViewMatrixBase == 0)
	//{
	//	m_drv->Unload();
	//	MessageBox(NULL, L"Can't Find ViewMatrixBase", L"Darkness", MB_OKCANCEL);
	//	ExitProcess(0);
	//}



	string MainFontPath = ("C:\\X.ttf");
	string RenderFontPath = ("C:\\X.ttf");

	scrWidthh = Rect.right - Rect.left;
	scrHeightt = Rect.bottom - Rect.top;
	DX11Window::Instantiate(Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top);
	DX11::Instantiate(DX11Window::hWindow, DX11Window::Width, DX11Window::Height);

	ImGui::CreateContext();
	RunStyle();

	ImGuiIO& Io = ImGui::GetIO();
	Io.WantSaveIniSettings = true;



	static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
	ImFontConfig icons_config;

	ImFontConfig CustomFont;
	CustomFont.FontDataOwnedByAtlas = false;


	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	icons_config.OversampleH = 2.5;
	icons_config.OversampleV = 2.5;




	
	Io.IniFilename = nullptr; 
	Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 15.0f);
	Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 16.0f, &icons_config, icons_ranges);



	ImGui_ImplWin32_Init(DX11Window::hWindow);
	ImGui_ImplDX11_Init(DX11::pDevice, DX11::pImmediateContext);
	DX11::ImGui_DX11::special = Io.Fonts->AddFontFromFileTTF(MainFontPath.c_str(), 32.0f);
	DX11::ImGui_DX11::pRegularFont = Io.Fonts->AddFontFromFileTTF(RenderFontPath.c_str(), 32.0f);
	DX11::ImGui_DX11::pIconFont = Io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 40.0f, &icons_config, icons_ranges);


	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Esp::EspThread, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Data::QueryThread, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Aimbot::AimbotThread, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Memory::MemoryThread, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Memory::AllMemoryHacks, 0, 0, 0));

	MSG Message;


	while (true)
	{


		if (PeekMessage(&Message, DX11Window::hWindow, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		//RECT Rect;
		//RECT res;
		//if (Game::hWindow)
		//{
		//	//GetClientRect(Game::hWindow, &Rect);
		//	GetWindowRect(Game::hWindow, &Rect);
		//	DX11Window::Left = Rect.left;
		//	DX11Window::Top = Rect.top;
		//	if (DX11Window::Width != (Rect.right - Rect.left) || DX11Window::Height != (Rect.bottom - Rect.top))
		//	{
		//		DX11Window::Width = Rect.right - Rect.left;
		//		DX11Window::Height = Rect.bottom - Rect.top;

		//	}
		//	SetWindowPos(DX11Window::hWindow, HWND_TOPMOST, Rect.left, Rect.top, scrWidth, scrHeight, SWP_NOMOVE | SWP_NOSIZE);
		//	MoveWindow(DX11Window::hWindow, Rect.left, Rect.top, scrWidth, scrHeight, TRUE);
		//	DwmExtendFrameIntoClientArea(DX11Window::hWindow, &DX11Window::Margins);

		//}
		RECT Rect;
		GetWindowRect(Game::hWindow, &Rect);
		DX11Window::Left = Rect.left;
		DX11Window::Top = Rect.top;
		DX11Window::Width = Rect.right - Rect.left;
		DX11Window::Height = Rect.bottom - Rect.top;
		MoveWindow(DX11Window::hWindow, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, true);
		if (Settings::ShowMenu)
		{
			SetForegroundWindow(DX11Window::hWindow);
		}

		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			if (DX11Window::IsClickable == true)
			{
				Utility::ChangeClickability(FALSE, DX11Window::hWindow);
				DX11Window::IsClickable = !DX11Window::IsClickable;
				Settings::ShowMenu = !Settings::ShowMenu;
			}
			else
			{
				Utility::ChangeClickability(TRUE, DX11Window::hWindow);
				DX11Window::IsClickable = !DX11Window::IsClickable;
				Settings::ShowMenu = !Settings::ShowMenu;
			}
		}
		if (GetAsyncKeyState(VK_HOME) & 1)
		{
			Settings::ShowMenu2 = !Settings::ShowMenu2;
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			Memory::RestoreHook();
			Sleep(200);
			m_drv->Unload();
			ExitProcess(1);
		}
		Sleep(10);

	}

	return EXIT_SUCCESS;
}