#include "Algorithm.h"

BOOL Algorithm::WorldToScreen(VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix)
{
	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	*Distance = (ScreenW / 100);
	if (ScreenW < 0.0001f) return FALSE;

	ScreenW = 1 / ScreenW;
	FLOAT SightX = (DX11Window::Width / 2);
	FLOAT SightY = (DX11Window::Height / 2);

	Screen.X = SightX + (ViewMatrix._11 * Position.X + ViewMatrix._21 * Position.Y + ViewMatrix._31 * Position.Z + ViewMatrix._41) * ScreenW * SightX;
	Screen.Y = SightY - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * Position.Z + ViewMatrix._42) * ScreenW * SightY;

	return TRUE;
}


VECTOR3 Algorithm::Subtract(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result;
	Result.X = Src.X - Dst.X;
	Result.Y = Src.Y - Dst.Y;
	Result.Z = Src.Z - Dst.Z;
	return Result;
}

VECTOR3 Algorithm::WorldToRadar(float Yaw, VECTOR3 Origin, VECTOR3 LocalOrigin, float PosX, float PosY, VECTOR3 Size, bool& outbuff)
{
	bool flag = false;
	double num = (double)Yaw;
	double num2 = num * 0.017453292519943295;
	float num3 = (float)std::cos(num2);
	float num4 = (float)std::sin(num2);
	float num5 = Origin.X - LocalOrigin.X;
	float num6 = Origin.Y - LocalOrigin.Y;
	VECTOR3 vector;
	vector.X = (num6 * num3 - num5 * num4) / 150.f;
	vector.Y = (num5 * num3 + num6 * num4) / 150.f;
	VECTOR3 vector2;
	vector2.X = vector.X + PosX + Size.X / 2.f;
	vector2.Y = -vector.Y + PosY + Size.Y / 2.f;
	bool flag2 = vector2.X > PosX + Size.X;
	if (flag2)
	{
		vector2.X = PosX + Size.X;
	}
	else
	{
		bool flag3 = vector2.X < PosX;
		if (flag3)
		{
			vector2.X = PosX;
		}
	}
	bool flag4 = vector2.Y > PosY + Size.Y;
	if (flag4)
	{
		vector2.Y = PosY + Size.Y;
	}
	else
	{
		bool flag5 = vector2.Y < PosY;
		if (flag5)
		{
			vector2.Y = PosY;
		}
	}
	bool flag6 = vector2.Y == PosY || vector2.X == PosX;
	if (flag6)
	{
		flag = true;
	}
	outbuff = flag;
	return vector2;
}

BOOL Algorithm::WorldToScreenPlayer(VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix)
{
	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	*Distance = (ScreenW / 100);
	if (ScreenW < 0.0001f) return FALSE;

	FLOAT ScreenX = (ViewMatrix._11 * Position.X) + (ViewMatrix._21 * Position.Y) + (ViewMatrix._31 * Position.Z + ViewMatrix._41);
	FLOAT ScreenY = (ViewMatrix._12 * Position.X) + (ViewMatrix._22 * Position.Y) + (ViewMatrix._32 * (Position.Z + 85) + ViewMatrix._42);

	Screen.X = (DX11Window::Width / 2) + (DX11Window::Width / 2) * ScreenX / ScreenW;
	Screen.Y = (DX11Window::Height / 2) - (DX11Window::Height / 2) * ScreenY / ScreenW;
	FLOAT Y1 = (DX11Window::Height / 2) - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * (Position.Z - 95) + ViewMatrix._42) * (DX11Window::Height / 2) / ScreenW;
	Screen.Z = Y1 - Screen.Y;

	return TRUE;
}

BOOL Algorithm::WorldToScreenBone(D3DMATRIX ViewMatrix, VECTOR3 Position, VECTOR2& Screen, INT* Distance)
{
	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	*Distance = (ScreenW / 100);
	if (ScreenW < 0.0001f) return FALSE;

	ScreenW = 1 / ScreenW;
	FLOAT SightX = (DX11Window::Width / 2);
	FLOAT SightY = (DX11Window::Height / 2);

	Screen.X = SightX + (ViewMatrix._11 * Position.X + ViewMatrix._21 * Position.Y + ViewMatrix._31 * Position.Z + ViewMatrix._41) * ScreenW * SightX;
	Screen.Y = SightY - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * Position.Z + ViewMatrix._42) * ScreenW * SightY;

	return TRUE;
}

D3DMATRIX Algorithm::ToMatrixWithScale(VECTOR3 Translation, VECTOR3 Scale, VECTOR4 Rot)
{
	D3DMATRIX m;
	m._41 = Translation.X;
	m._42 = Translation.Y;
	m._43 = Translation.Z;

	FLOAT x2 = Rot.X + Rot.X;
	FLOAT y2 = Rot.Y + Rot.Y;
	FLOAT z2 = Rot.Z + Rot.Z;

	FLOAT xx2 = Rot.X * x2;
	FLOAT yy2 = Rot.Y * y2;
	FLOAT zz2 = Rot.Z * z2;
	m._11 = (1.0f - (yy2 + zz2)) * Scale.X;
	m._22 = (1.0f - (xx2 + zz2)) * Scale.Y;
	m._33 = (1.0f - (xx2 + yy2)) * Scale.Z;

	FLOAT yz2 = Rot.Y * z2;
	FLOAT wx2 = Rot.W * x2;
	m._32 = (yz2 - wx2) * Scale.Z;
	m._23 = (yz2 + wx2) * Scale.Y;

	FLOAT xy2 = Rot.X * y2;
	FLOAT wz2 = Rot.W * z2;
	m._21 = (xy2 - wz2) * Scale.Y;
	m._12 = (xy2 + wz2) * Scale.X;

	FLOAT xz2 = Rot.X * z2;
	FLOAT wy2 = Rot.W * y2;
	m._31 = (xz2 + wy2) * Scale.Z;
	m._13 = (xz2 - wy2) * Scale.X;

	m._14 = 0.0f;
	m._24 = 0.0f;
	m._34 = 0.0f;
	m._44 = 1.0f;

	return m;
}

D3DMATRIX Algorithm::MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut =
	{
		pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41,
		pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42,
		pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43,
		pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44,
		pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41,
		pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42,
		pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43,
		pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44,
		pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41,
		pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42,
		pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43,
		pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44,
		pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41,
		pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42,
		pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43,
		pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44
	};

	return pOut;
}

VECTOR3 Algorithm::GetBoneWorldPosition(DWORD ActorAddv, DWORD BoneAddv)
{
	FTTransform Bone = Utility::ReadMemoryEx<FTTransform>(BoneAddv);
	FTTransform Actor = Utility::ReadMemoryEx<FTTransform>(ActorAddv);
	D3DMATRIX BoneMatrix = ToMatrixWithScale(Bone.Translation, Bone.Scale3D, Bone.Rotation);
	D3DMATRIX ComponentToWorldMatrix = ToMatrixWithScale(Actor.Translation, Actor.Scale3D, Actor.Rotation);
	D3DMATRIX NewMatrix = MatrixMultiplication(BoneMatrix, ComponentToWorldMatrix);

	VECTOR3 BonePos;
	BonePos.X = NewMatrix._41;
	BonePos.Y = NewMatrix._42;
	BonePos.Z = NewMatrix._43;

	return BonePos;
}
