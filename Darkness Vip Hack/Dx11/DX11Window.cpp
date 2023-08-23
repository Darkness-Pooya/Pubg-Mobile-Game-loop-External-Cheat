#include "DX11Window.h"
#include<thread>
HWND DX11Window::hWindow;
MARGINS DX11Window::Margins;
INT DX11Window::Left;
INT DX11Window::Top;
INT DX11Window::Width;
INT DX11Window::Height;
bool DX11Window::IsClickable = true;
BOOL DX11Window::Instantiate(INT Left, INT Top, INT Width, INT Height)
{
	DX11Window::Left = Left;
	DX11Window::Top = Top;
	DX11Window::Width = Width;
	DX11Window::Height = Height;

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = DX11Window::WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = 0;
	wc.hCursor = 0;
	wc.hbrBackground = 0;
	wc.lpszMenuName = "";
	wc.lpszClassName = "DX11WindowClass";
	wc.hIconSm = 0;

	RegisterClassEx(&wc);
	DX11Window::hWindow = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_NOACTIVATE, "DX11WindowClass", "DX11Window", WS_POPUP, DX11Window::Left, DX11Window::Top, DX11Window::Width, DX11Window::Height, 0, 0, 0, 0);
	if (DX11Window::hWindow == 0x0) return FALSE;

	DX11Window::Margins = { -1, -1, -1, -1 };
	SetLayeredWindowAttributes(DX11Window::hWindow, 0, 255, LWA_ALPHA);
	//	SetWindowLong(DX11Window::hWindow, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	DwmExtendFrameIntoClientArea(DX11Window::hWindow, &DX11Window::Margins);
	ShowWindow(DX11Window::hWindow, SW_SHOW);

	//UpdateWindow(DX11Window::hWindow);
	return TRUE;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK DX11Window::WndProc(HWND hWindow, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWindow, Message, wParam, lParam)) return true;

	switch (Message)
	{

	case WM_QUIT:
		ExitProcess(0);
		break;
	case WM_CLOSE:
		ExitProcess(0);
		break;
	case WM_DESTROY:
		ExitProcess(0);
		break;

		break;
	case WM_SIZE:
		if (DX11::pDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX11_InvalidateDeviceObjects();
			RECT Rect;
			GetWindowRect(Game::hWindow, &Rect);

			if (DX11::pSwapChain)
			{
				DX11::pImmediateContext->OMSetRenderTargets(0, 0, 0);


				DX11::pRenderTargetView->Release();

				HRESULT hr;

				hr = DX11::pSwapChain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);

				ID3D11Texture2D* pBuffer;
				hr = DX11::pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
					(void**)&pBuffer);

				hr = DX11::pDevice->CreateRenderTargetView(pBuffer, NULL,
					&DX11::pRenderTargetView);

				pBuffer->Release();

				DX11::pImmediateContext->OMSetRenderTargets(1, &DX11::pRenderTargetView, NULL);
				if (DX11Window::Left != Rect.left || DX11Window::Top != Rect.top)
				{
					DX11Window::Left = Rect.left;
					DX11Window::Top = Rect.top;

					if (DX11Window::Width != (Rect.right - Rect.left) || DX11Window::Height != (Rect.bottom - Rect.top))
					{
						DX11Window::Width = Rect.right - Rect.left;
						DX11Window::Height = Rect.bottom - Rect.top;
					}
					else
					{
						exit(51252);

					}

				}

				D3D11_VIEWPORT vp;
				vp.Width = DX11Window::Width;
				vp.Height = DX11Window::Height;
				vp.MinDepth = 0.0f;
				vp.MaxDepth = 1.0f;
				vp.TopLeftX = 0;
				vp.TopLeftY = 0;
				DX11::pImmediateContext->RSSetViewports(1, &vp);
			}
			ImGui_ImplDX11_CreateDeviceObjects();
			break;
		}
		break;
	default:
		return DefWindowProc(hWindow, Message, wParam, lParam);
		break;
	}

	return 0;
}


