#pragma once

#include "Includes.h"
#include "Algorithm\Algorithm.h"
#include "Dx11\DX11.h"
#include ".\Dx11\DX11Window.h"
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"
#include "..\Algorithm\Algorithm.h"

void ipad();

void WriteUE4Float(DWORD offset, float replace);

void ReplaceOffset(int offset, BYTE write[], SIZE_T size, int header);

namespace Esp
{
	extern D3DMATRIX ViewMatrix;
	void LoadConfig(std::string Path);
	VOID EspThread();
}
