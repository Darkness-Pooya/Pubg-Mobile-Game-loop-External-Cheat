#pragma once
#include <d3d11.h>
#include <D3DX11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <xnamath.h>
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "d3dx11.lib")

#include "Includes.h"

#include "imgui-docking/imgui.h"
#include "imgui-docking/imgui_impl_win32.h"
#include "imgui-docking/imgui_impl_dx11.h"
#include "imgui-docking/imgui_internal.h"

const char VertexShader[] =
{
"struct VS_OUTPUT\n"
"{\n"
	"float4 Pos : SV_POSITION;\n"
	"float4 Color : COLOR;\n"
"};\n"
"VS_OUTPUT VS(float4 inPos : POSITION, float4 inColor : COLOR)\n"
"{\n"
	"VS_OUTPUT output;\n"

	"output.Pos = inPos;\n"
	"output.Color = inColor;\n"

	"return output;\n"
"}\n"
};

const char PixelShader[] =
{
"struct VS_OUTPUT\n"
"{\n"
"float4 Pos : SV_POSITION;\n"
"float4 Color : COLOR;\n"
"};\n"
"float4 PS(VS_OUTPUT input) : SV_TARGET\n"
"{\n"
"return input.Color;\n"
"}\n"
};

struct VERTEX
{
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
};

namespace DX11
{
	extern FLOAT alpha;
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pImmediateContext;
	extern IDXGISwapChain* pSwapChain;
	extern ID3D11RenderTargetView* pRenderTargetView;
	extern ID3D11VertexShader* pVertexShader;
	extern ID3D11PixelShader* pPixelShader;
	extern ID3D11InputLayout* pVertexLayout;
	extern ID3D11Buffer* pVertexBuffer;
	extern ID3D11Texture2D* pDepthStencilBuffer;
	extern ID3D11DepthStencilView* pDepthStencilView;
	extern ID3D11DepthStencilState* pDepthStencilState;
	extern ID3D11RasterizerState* pRasterizerState;
	extern ID3D11BlendState* pBlendState;

	BOOL Instantiate(HWND hWindow, INT Width, INT Height);
	VOID BeginDraw();
	VOID ClearSurface();
	VOID EndDraw();
	VOID DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, XMFLOAT4 Color);
	VOID DrawCircle(FLOAT X, FLOAT Y, UINT Radius, XMFLOAT4 Color);
	VOID DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color);
	VOID DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, XMFLOAT4 Color);

	namespace ImGui_DX11
	{
		extern ImDrawList* pImGuiDraw;
		extern ImFont* pRegularFont;
		extern ImFont* pic;

		extern ImFont* special;
		extern ImFont* pIconFont;
		void AimLine(int x, int y, int x1, int y1, ImColor color, float thickness);
		void DrawFilledRect(int x, int y, int w, int h, uint32_t color);
		void CornerBox(int x, int y, int w, int h, int thickness, float cornered, ImColor color);
		void DrawBlood(float x, float y, float w, float h, float fBlood);
		VOID DrawCircle3(int x, int y, int radius, ImColor Color, int segments);
		VOID DrawCircle2(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness = 1);
		VOID SpText(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness = 1);
		VOID DrawCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness = 1);
		VOID DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness = 1);
		VOID DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color);
		VOID DrawString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID DrawBorderString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center);
		VOID Tri(FLOAT X, FLOAT Y, ImColor Color);
		namespace Color
		{
			const ImColor White = ImColor(255, 255, 255);
			const ImColor enem = ImColor{ 1.00f, 0.27f, 0.00f, 1.0f };
			const ImColor Black = ImColor(0, 0, 0);
			const ImColor Red = ImColor(255, 0, 0);
			const ImColor aqua = ImColor(0, 255, 242);
			const ImColor Green = ImColor(0, 255, 0);
			const ImColor Blue = ImColor(0, 150, 255);
			const ImColor Yellow = ImColor(255, 255, 0);
			const ImColor Cyan = ImColor(0, 180, 255);
			const ImColor Orange = ImColor(255, 165, 0);
			const ImColor Maroon = ImColor(128, 0, 0);
			const ImColor Magenta = ImColor(255, 0, 255);
			const ImColor Olive = ImColor(128, 128, 0);
			const ImColor Purple = ImColor(128, 0, 128);
			const ImColor Chocolate = ImColor(255, 127, 36);

			const ImColor White2 = ImColor(255, 25, 255);
			const ImColor enem2 = ImColor{ 1.00f, 0.7f, 0.200f, 1.0f };
			const ImColor Black2 = ImColor(20, 20, 20);
			const ImColor Red2 = ImColor(255, 30, 30);
			const ImColor Green2 = ImColor(30, 255, 30);
			const ImColor Blue2 = ImColor(30, 150, 255);
		}
	}
}