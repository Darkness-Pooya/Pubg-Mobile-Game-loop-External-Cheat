
#include "Memory.h"
#include "Aimbot\Aimbot.h"
#include <thread>

BYTE MagicBulletShell[60]
{
	  0xC7, 0x45, 0x78, 0x4B, 0x48, 0x41, 0x4E,
	  0x83, 0x3D, 0x00, 0x0A, 0x52, 0x55, 0x45,
	  0x74, 0x0E,
	  0x60,
	  0x8B, 0x5D, 0x50,
	  0x8B, 0x53, 0x18,
	  0x8A, 0x02,
	  0x3C, 0x34,  // Need update
	  0x74, 0x02,
	  0x61,
	  0xC3,
	  0x8A, 0x42, 0x01,
	  0x3C, 0x13, // Need update
	  0x75, 0x14,
	  0xC7, 0x83, 0x20, 0x02, 0x00, 0x00, 0x50, 0x45, 0x4F, 0x00,
	  0xC7, 0x83, 0x24, 0x02, 0x00, 0x00, 0x50, 0x4C, 0x45, 0x00,
	  0xEB, 0xE1
};



BYTE MagicBulletSearch1[] = { 0x66, 0x0F, 0x7E, '?', 0x28, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0x78 }; // Need update
BYTE MagicBulletSearch2[] = { 0x66, 0x0F, 0x7E, '?', 0x28, 0x02, 0x00, 0x00, 0xC7, 0x45, '?', 0x78 }; // Need update


DWORD MagicBulletAddress = 0;
vector<DWORD_PTR> MagicBulletList = {};
INT MagicBulletHook = 0;
BYTE RealByteCode[7];
VOID GetMagicAddress()
{
	std::vector<DWORD_PTR> FoundedBase;
	{
		Utility::MemSearch(MagicBulletSearch1, sizeof(MagicBulletSearch1), 0x0D000000, 0x10000000, 0, 0, FoundedBase);
	}

	for (int i = 0; i < FoundedBase.size(); i++)
	{
		if (Utility::ReadMemoryEx<BYTE>(FoundedBase[i] + 0xC) == 0x47) // Need update
		{
			MagicBulletList.push_back(FoundedBase[i]);
			MagicBulletAddress = FoundedBase[i];
		}
	}

	FoundedBase.resize(0);
}

VOID InitializeMagic()
{
	INT Addv = MagicBulletAddress;

	WriteProcessMemory(Game::hProcess, (LPVOID)MagicBulletHook, &MagicBulletShell, sizeof(MagicBulletShell), 0);

	MagicBulletHook = (INT)VirtualAllocEx(Game::hProcess, 0, 500, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(Game::hProcess, (LPVOID)MagicBulletHook, &MagicBulletShell, sizeof(MagicBulletShell), 0);

	if (Emulator::IsGameLoop4 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x40);
	}
	else if (Emulator::IsGameLoop7 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x50);
	}
	if (Emulator::IsSmartGaGa4 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x40);
	}
	else if (Emulator::IsSmartGaGa7 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x50);
	}

	Utility::WriteMemoryEx<INT>(MagicBulletHook + 9, MagicBulletHook + 0x5E);
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
	WriteProcessMemory(Game::hProcess, (LPVOID)(MagicBulletHook), &RealByteCode, sizeof(RealByteCode), 0);
}

VOID HookCall(INT Address, INT HookAdress)
{
	BYTE Shell[7] = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 };
	*(INT*)(Shell + 1) = (INT)(HookAdress - Address - 5);
	WriteProcessMemory(Game::hProcess, (LPVOID)Address, &Shell, sizeof(Shell), 0);
}

bool IsEqual(BYTE Array1[], BYTE Array2[])
{
	for (int i = 0; i < 6; i++)
	{
		if (Array1[i] != Array2[i])
		{
			return false;
		}
	}

	return true;
}

bool Hooked(int Address)
{
	unsigned char Tmp[7];
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Address + 0x8), &Tmp, sizeof(Tmp), 0);

	if ((Tmp[0] == 0xE8 && Tmp[5] == 0x90 && Tmp[6] == 0x90))
	{
		return true;
	}

	return false;
}

VOID HookMagic()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		BYTE Tmp[7];
		ReadProcessMemory(Game::hProcess, (LPCVOID)((int)Addv + 0x8), &Tmp, sizeof(Tmp), 0);

		if (IsEqual(Tmp, RealByteCode))
		{
			HookCall((INT)(Addv + 0x8), (INT)MagicBulletHook);
		}
	}
}

VOID Memory::RestoreHook()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		if (Hooked(Addv))
		{
			WriteProcessMemory(Game::hProcess, (LPVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
		}
	}
}

VECTOR3 Subtract(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result;
	Result.X = Src.X - Dst.X;
	Result.Y = Src.Y - Dst.Y;
	Result.Z = Src.Z - Dst.Z;
	return Result;
}

float Magnitude(VECTOR3 Vec)
{
	return sqrtf(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z);
}

float GetDistance(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result = Subtract(Src, Dst);
	return Magnitude(Result);
}

VECTOR3 NormalizeVec(VECTOR3 Vector)
{
	float Length = Magnitude(Vector);

	Vector.X /= Length;
	Vector.Y /= Length;
	Vector.Z /= Length;

	return Vector;
}
float Distance(VECTOR3 myPos, VECTOR3 enPos)
{
	return sqrt((myPos.X - enPos.X) * (myPos.X - enPos.X) + (myPos.Y - enPos.Y) * (myPos.Y - enPos.Y) + (myPos.Z - enPos.Z) * (myPos.Z - enPos.Z));
}
float BulletDrop(float TravelTime)
{
	return (TravelTime * TravelTime * 980 / 2);
}
bool Fov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius)
{
	VECTOR2 Cenpoint;
	Cenpoint.X = PlayerW2SBone.X - (OverlayScreenWidth / 2);
	Cenpoint.Y = PlayerW2SBone.Y - (OverlayScreenHeight / 2);

	if (Cenpoint.X * Cenpoint.X + Cenpoint.Y * Cenpoint.Y <= FovRadius * FovRadius)
	{
		return true;
	}

	return false;
}
bool bIsPressingFireBtn;

VECTOR2 GetMagicCoordinates()
{
	if (Data::AActorList.size() > 0)
	{
		VECTOR2 Coordinate;
		Coordinate.X = 0;
		Coordinate.Y = 0;
		VECTOR3 HeadPos;
		HeadPos.X = 0;
		HeadPos.Y = 0;
		HeadPos.Z = 0;
		VECTOR2 Screen;
		Screen.X = 0;
		Screen.Y = 0;
		VECTOR3 Velocity;
		Velocity.X = 0;
		Velocity.Y = 0;
		Velocity.Z = 0;
		FLOAT TargetDistance = 9999.0f;
		FLOAT CrossDist = 0;
		INT Distance4 = 0;
		VECTOR3 posi;
		int Distancee;
		VECTOR3 Screenn;

		for (AActor& AActor : Data::AActorList)
		{


			if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.HeadPos, Screen, &Distance4))
			{


				if (Settings::Fovbased)
				{
					if (Aimbot::InsideFov(DX11Window::Width, DX11Window::Height, Screen, Settings::fovcircleredus/*FovRadius*/))
					{



						//no will fix your prop
						HookMagic();
						if ((AActor.IsBot == true && Settings::SkipBots == true))continue;
						if ((AActor.Health <= 0 && Settings::knocked == false))continue;

						if (Distance4 > Settings::MaxAimDistence)continue;
						CrossDist = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));
						if (CrossDist < TargetDistance)
						{

							if (Settings::curraim == 0)
							{
								HeadPos = AActor.HeadPos;
								HeadPos.Z += 7;
							}
							if (Settings::curraim == 1)
							{
								HeadPos = AActor.ChestPos;
							}
							if (Settings::curraim == 2)
							{
								HeadPos = AActor.PelvisPos;
							}
							TargetDistance = CrossDist;
							Velocity = AActor.Velocity;
						}

					}

				}
				else
				{
					HookMagic();
					if ((AActor.IsBot == true && Settings::SkipBots == true))continue;
					if ((AActor.Health <= 0 && Settings::knocked == false))continue;

					if (Distance4 > Settings::MaxAimDistence)continue;

					{
						CrossDist = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));

						if (CrossDist < TargetDistance)
						{

							if (Settings::curraim == 0)
							{
								HeadPos = AActor.HeadPos;
								HeadPos.Z += 7;
							}
							if (Settings::curraim == 1)
							{
								HeadPos = AActor.ChestPos;
							}
							if (Settings::curraim == 2)
							{
								HeadPos = AActor.PelvisPos;
							}



							TargetDistance = CrossDist;
							Velocity = AActor.Velocity;
						}


					}

				}

			}

		}

		DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Bone::Mesh);
		DWORD BodyAddv = MeshAddv + Offset::Bone::BodyAddv;
		DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::Bone::MinLOD) + 48;
		VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);

		float AddTime = 30 / 10.0f + 1.0f;
		float Gravity = 5.72f;
		float distance = GetDistance(MyPosition, HeadPos) / 100.0f;
		float zAssist;
		float Distance = GetDistance(MyPosition, HeadPos) / 100.0f;

		float BulletTravelTime = Distance / Offset::Hacks::BulletFireSpeed;
		if (Distance < 5000.f)
			zAssist = 1.8f;
		else if (Distance < 10000.f)
			zAssist = 1.72f;
		else if (Distance < 15000.f)
			zAssist = 1.23f;
		else if (Distance < 20000.f)
			zAssist = 1.24f;
		else if (Distance < 25000.f)
			zAssist = 1.25f;
		else if (Distance < 30000.f)
			zAssist = 1.26f;
		else if (Distance < 35000.f)
			zAssist = 1.27f;
		else if (Distance < 40000.f)
			zAssist = 1.28f;
		else if (Distance < 45000.f)
			zAssist = 1.29f;
		else if (Distance < 50000.f)
			zAssist = 1.30f;


		HeadPos.X += Velocity.X * BulletTravelTime;
		HeadPos.X += Velocity.X * BulletTravelTime;
		HeadPos.Y += Velocity.Y * BulletTravelTime;
		HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;


		FLOAT xDif = HeadPos.X - MyPosition.X;
		FLOAT yDif = HeadPos.Y - MyPosition.Y;
		FLOAT zDif = HeadPos.Z - MyPosition.Z;

		float Hyp = sqrt(xDif * xDif + yDif * yDif);
		Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
		Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

		return Coordinate;


	}
	else
	{
		Memory::RestoreHook();
		MagicBulletList.clear();
		VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
		MagicBulletAddress = 0;
		MagicBulletHook = 0;
		ZeroMemory(RealByteCode, sizeof(RealByteCode));
		Memory::IsMagicInitialized = false;
	}
}




bool  Memory::IsMagicInitialized = false;



VOID Memory::MemoryThread()
{
	static bool BulletKeyState = false;
	VECTOR2 MagicCoordinate;
	VECTOR3 AimRotation{};

	while (true)
	{

		if (Data::NetDriver > 0)
		{
			if (Settings::MagicBullet)
			{
				if (IsMagicInitialized == false)
				{
					GetMagicAddress();
					InitializeMagic();
					IsMagicInitialized = true;
				}
				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{

					MagicCoordinate = GetMagicCoordinates();

					Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 44, MagicCoordinate.X);
					Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 54, MagicCoordinate.Y);
				}

				// Refresh magic
				if (GetAsyncKeyState(0x52) & 1)
				{
					if (IsMagicInitialized == true)
					{
						if (Data::NetDriver > 0)
						{
							RestoreHook();
							MagicBulletList.clear();
							VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
							MagicBulletAddress = 0;
							MagicBulletHook = 0;
							ZeroMemory(RealByteCode, sizeof(RealByteCode));
							IsMagicInitialized = false;
						}
					}
				}

			}
			else if (Settings::MagicBullet == false && IsMagicInitialized == true)
			{
				RestoreHook();
				MagicBulletList.clear();
				VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
				MagicBulletAddress = 0;
				MagicBulletHook = 0;
				ZeroMemory(RealByteCode, sizeof(RealByteCode));
				//    MagicRested = false;
				IsMagicInitialized = false;
			}

		}

		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
}
VECTOR3 ClosestToCrosshair()
{
	float targetDistance = 500.0f;
	VECTOR2 retval;
	int dist, headdist;
	VECTOR3 ret;
	for (int i = 0; i < Data::AActorList.size(); i++) {
		DWORD tmpAddv = Utility::ReadMemoryEx<INT>(Data::AActorList[i].Address + Offset::Bone::Mesh);
		DWORD bodyAddv = tmpAddv + Offset::Bone::BodyAddv;
		DWORD boneAddv = Utility::ReadMemoryEx<INT>(tmpAddv + Offset::Bone::MinLOD) + 48;
		VECTOR2 chest;
		VECTOR2 head;
		//VECTOR3 chestPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 3 * 48); 
		VECTOR3 CurrPos = { 0 };
		if (Settings::curraim == 0) {
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 5 * 48);
			//CurrPos.z += 15; 
		}
		if (Settings::curraim == 1)
		{
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);
		}
		if (Settings::curraim == 2)
		{
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 1 * 48);
		}
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, CurrPos, chest, &dist))
		{
			if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, CurrPos, chest, &dist))
			{
				float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));

				if (cross_dist < targetDistance)
				{
					ret = CurrPos;
					targetDistance = cross_dist;

				}
			}

		}
	}
	return ret;
}
bool MagicX = false;
VOID ReplacePattern(BYTE* SearchPattern, BYTE* ReplacePattern)
{
	DWORD libUE4Base = Utility::ReadMemoryEx<DWORD>(0x0E0C3CE0);

	std::vector<DWORD_PTR> FoundedBase;
	Utility::MemSearch(SearchPattern, sizeof(SearchPattern), libUE4Base + 0x1F000000, 0xB0000000, 0, 0, FoundedBase);

	for (DWORD_PTR& Addv : FoundedBase)
	{
		Utility::WriteProtectedMemoryEx<BYTE[sizeof(ReplacePattern)]>(Addv, ReplacePattern);
	}
}
void Memory::AllMemoryHacks() {
	bool ipaddone = false;
	DWORD libUE4Base = Utility::ReadMemoryEx<DWORD>(0x0E0C3CE0);

	while (true) {

		if (Settings::Xeffect && MagicX == false)
		{
			BYTE pattern[] = { 0x00, 0x00, 0x20,0x41, 0x00, 0x00, 0x38, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F };
			BYTE patter2[] = { 0x00 ,0x08 ,0xF3,0x45, 0x00, 0x00, 0x38, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F };

			DWORD bytes;
			std::vector<DWORD_PTR> foundedBases2;
			DWORD oldprotect, temps;
			foundedBases2.resize(0);
			Utility::MemSearch(pattern, sizeof(pattern), libUE4Base + 0x7C1A4E5, 0xC0000000, false, 0, foundedBases2);

			for (int i = 0; i < foundedBases2.size(); i++)
			{
				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases2[i]), 4, PAGE_EXECUTE_READWRITE, &oldprotect);
				WriteProcessMemory(Game::hProcess, (PVOID)foundedBases2[i], patter2, sizeof(patter2), nullptr);
				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases2[i]), 4, oldprotect, &temps);

			}
			ReplacePattern(pattern, patter2);
			MagicX = true;
			//std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
		}
		else if (!Settings::Xeffect && MagicX == true)
		{
			BYTE pattern[] = { 0x00, 0x00, 0x20,0x41, 0x00, 0x00, 0x38, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F };
			BYTE patter2[] = { 0x00 ,0x08 ,0xF3,0x45, 0x00, 0x00, 0x38, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0x3F };

			DWORD bytes;
			std::vector<DWORD_PTR> foundedBases;
			DWORD oldprotect, temps;
			foundedBases.resize(0);

			Utility::MemSearch(patter2, sizeof(patter2), libUE4Base + 0x7C1A4E5, 0xC0000000, false, 0, foundedBases);

			for (int i = 0; i < foundedBases.size(); i++)
			{
				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases[i]), 4, PAGE_EXECUTE_READWRITE, &oldprotect);
				WriteProcessMemory(Game::hProcess, (PVOID)foundedBases[i], pattern, sizeof(pattern), nullptr);
				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases[i]), 4, oldprotect, &temps);

			}
			MagicX = false;
			//std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
		}
		if (Settings::AntiStream) {
			SetWindowDisplayAffinity(DX11Window::hWindow, WDA_EXCLUDEFROMCAPTURE);
		}
		else {
			SetWindowDisplayAffinity(DX11Window::hWindow, WDA_NONE);
		}
		//if (Settings::IpadView) {
		//	DWORD C = Utility::ReadMemoryEx<int>(Data::LocalPlayer + 0x139c) + 0x260;//CustomSpringArmComponent* SpringArmComp
		//	Utility::WriteMemoryEx<float>(C, Settings::IpadValue);

		//	ipaddone = true;
		//}
		//else if (!Settings::IpadView && ipaddone) {
		//	DWORD C = Utility::ReadMemoryEx<int>(Data::LocalPlayer + 0x139c) + 0x260; //CustomSpringArmComponent* SpringArmComp
		//	Utility::WriteMemoryEx<float>(C, 250.0f);
		//	ipaddone = false;
		//}
		if (Settings::NoRecoil) {
			DWORD CurrentWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Player::weaponOffset);

			DWORD ShootWeapon = Utility::ReadMemoryEx<int>(CurrentWeapon + 0xc40);

			if (ShootWeapon != 0)
			{
				Utility::WriteMemoryEx<float>(ShootWeapon + Offset::Hacks::AccessoriesVRecoilFactor, 0.0f);
				Utility::WriteMemoryEx<float>(ShootWeapon + Offset::Hacks::AccessoriesHRecoilFactor, 0.0f);
				Utility::WriteMemoryEx<float>(ShootWeapon + Offset::Hacks::AccessoriesRecoveryFactor, 0.0f);

			}
		}

		if (Settings::ForceTpp) {
			int ForceTPP = Utility::ReadMemoryEx<int>(Data::UWorld + 0x128);
			bool IsFPP = Utility::ReadMemoryEx<bool>(ForceTPP + Offset::Hacks::IsFPPGameMode);//bool IsFPPGameMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
			if (IsFPP)
			{
				Utility::WriteMemoryEx<DWORD>(ForceTPP + Offset::Hacks::IsFPPGameMode, 256);//bool IsFPPGameMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
			}
		}
		if (Settings::InstantHit) {
			float write = 0.0f;
			DWORD CurrentWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Player::weaponOffset);

			if (CurrentWeapon != 0)
			{
				DWORD ShootWeapon = Utility::ReadMemoryEx<int>(CurrentWeapon + Offset::Hacks::CurShootIntervalMode);

				if (ShootWeapon != 0)
				{
					DWORD insrd = Utility::ReadMemoryEx<float>(ShootWeapon + Offset::Hacks::BulletFireSpeed);
					if (insrd != 600000.0f && insrd != 0.0f)
					{
						Utility::WriteMemoryEx<float>(ShootWeapon + Offset::Hacks::BulletFireSpeed, Settings::InstantValue);
					}
				}
			}

		}
		if (Settings::Magic360)
		{
			DWORD LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STExtraPlayerCharacter::STPlayerController);
			if (LocalController)
			{
				DWORD Controller1 = 0x30c;//	Controller* Controller;//[Offset: 0x30c, Size: 4]
				DWORD ControlRotation = 0x308;//	Rotator ControlRotation;//[Offset: 0x308, Size: 12]

				DWORD PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::Camera::PlayerCameraManager);
				if (PlayerCameraManager)
				{
					CameraCacheEntry CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::Camera::CameraCache);

					VECTOR3 HeadPosition = ClosestToCrosshair();
					VECTOR3 currentViewAngle = CameraCache.POV.Location;

					if (GetAsyncKeyState(VK_LBUTTON))
					{

						//FRotator aimRotation = ToRotator(currentViewAngle, HeadPosition);
						//CameraCache.POV.Rotation = aimRotation;
						//Utility::WriteMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::Camera::CameraCache, CameraCache);

					}
				}
			}
		}
		if (Settings::NoSpread) {
			DWORD CurrentWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Player::weaponOffset);

			DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentWeapon + Offset::ShootWeaponEntity);

			float GameDeviationFactor = Utility::ReadMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::GameDeviationFactor);
			float ShotGunHorizontalSpread = Utility::ReadMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShotGunHorizontalSpread);
			float ShotGunVerticalSpread = Utility::ReadMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShotGunVerticalSpread);
			if (GameDeviationFactor != 0 && ShotGunHorizontalSpread != 0 && ShotGunVerticalSpread != 0)
			{
				Utility::WriteMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::GameDeviationFactor, 0);
				Utility::WriteMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShotGunHorizontalSpread, 0);
				Utility::WriteMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShotGunVerticalSpread, 0);
			}
		}

		if (Settings::FastSwitch) {
			float SwitchWeaponSpeedScale = Utility::ReadMemoryEx<float>(Data::LocalPlayer + Offset::Hacks::SwitchWeaponSpeedScale);
			if (SwitchWeaponSpeedScale != 100)
			{
				Utility::WriteMemoryEx<float>(Data::LocalPlayer + Offset::Hacks::SwitchWeaponSpeedScale, 100);

			}
		}

		if (Settings::RepidFire) {
			DWORD CurrentWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Player::weaponOffset);

			DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentWeapon + Offset::ShootWeaponEntity);

			float ShootInterval = Utility::ReadMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShootInterval);
			if (ShootInterval != 0.02f)
			{
				Utility::WriteMemoryEx<float>(ShootWeaponEntity + Offset::Hacks::ShootInterval, 0.02f);

			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}