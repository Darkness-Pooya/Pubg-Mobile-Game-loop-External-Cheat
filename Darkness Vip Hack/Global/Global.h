#pragma once

#include "Includes.h"

#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

namespace Emulator
{
	extern bool IsSmartGaGa;
	extern bool IsSmartGaGa4;
	extern bool IsSmartGaGa7;
	extern bool IsGameLoop;
	extern bool IsGameLoop4;
	extern bool IsGameLoop7;
}

namespace Game
{
	extern INT Id;
	extern HANDLE hProcess;
	extern HWND hWindow;
}
