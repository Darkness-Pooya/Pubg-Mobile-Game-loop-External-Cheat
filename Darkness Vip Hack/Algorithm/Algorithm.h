#pragma once

#include "Includes.h"
#include "Utility\Utility.h"
#include "Dx11\\DX11Window.h"

#define M_PI 3.14159265358979323846f


typedef struct D3DMATRIX1 {
	float m[4][4];
}
D3DMATRIX1, * LPD3DMATRIX;

struct VECTOR2
{
	FLOAT X = 0;
	FLOAT Y = 0;
};

struct VECTOR3
{
	FLOAT X = 0;
	FLOAT Y = 0;
	FLOAT Z = 0;
};

struct VECTOR4
{
	FLOAT X = 0;
	FLOAT Y = 0;
	FLOAT Z = 0;
	FLOAT W = 0;
};

struct D3DMATRIX
{
	FLOAT _11, _12, _13, _14;
	FLOAT _21, _22, _23, _24;
	FLOAT _31, _32, _33, _34;
	FLOAT _41, _42, _43, _44;
};

struct FTTransform
{
	VECTOR4 Rotation;
	VECTOR3 Translation;
	FLOAT _Padding;
	VECTOR3 Scale3D;
};

struct FRotator {
	float Pitch;
	float Yaw;
	float Roll;
};

struct MinimalViewInfo {
	VECTOR3 Location;
	VECTOR3 LocationLocalSpace;
	FRotator Rotation;
	float FOV;
};

struct CameraCacheEntry {
	float TimeStamp;
	char chunks[0xC];
	MinimalViewInfo POV;
};

namespace Algorithm
{
	BOOL WorldToScreen(VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix);
	VECTOR3 Subtract(VECTOR3 Src, VECTOR3 Dst);
	VECTOR3 WorldToRadar(float Yaw, VECTOR3 Origin, VECTOR3 LocalOrigin, float PosX, float PosY, VECTOR3 Size, bool& outbuff);
	BOOL WorldToScreenPlayer(VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix);
	BOOL WorldToScreenBone(D3DMATRIX ViewMatrix, VECTOR3 Position, VECTOR2& Screen, INT* Distance);
	D3DMATRIX ToMatrixWithScale(VECTOR3 Translation, VECTOR3 Scale, VECTOR4 Rot);
	D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2);
	VECTOR3 GetBoneWorldPosition(DWORD ActorAddv, DWORD BoneAddv);
}
