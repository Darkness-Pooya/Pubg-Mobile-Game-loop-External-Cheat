#pragma once

#include "Includes.h"
#include "DX11.h"
#include "Global\Global.h"
#include<thread>
#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

namespace DX11Window
{
	extern HWND hWindow;
	extern MARGINS Margins;
	extern INT Left;
	extern INT Top;
	extern INT Width;
	extern INT Height;
	extern bool IsClickable;

	BOOL Instantiate(INT Left, INT Top, INT Width, INT Height);
	LRESULT CALLBACK WndProc(HWND hWindow, UINT Message, WPARAM wParam, LPARAM lParam);
	VOID Move();
	void SetWindowToTarget();
}
