//#include "Aimbot.h"
//#include"Memory.h"
//#include<thread>
//
//
//bool Aimbot::InsideFov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius)
//{
//	VECTOR2 Cenpoint;
//	Cenpoint.X = PlayerW2SBone.X - (OverlayScreenWidth / 2);
//	Cenpoint.Y = PlayerW2SBone.Y - (OverlayScreenHeight / 2);
//
//	if (Cenpoint.X * Cenpoint.X + Cenpoint.Y * Cenpoint.Y <= FovRadius * FovRadius)
//	{
//		return true;
//	}
//
//
//	return false;
//}
//
//VECTOR2 Aimbot::GetClosestEnemy()
//{
//	float targetDistance = 9999.0;
//	VECTOR2 retval;
//	int dist, headdist;
//	VECTOR2 ret;
//	for (int i = 0; i < Data::AActorList.size(); i++) {
//		DWORD tmpAddv = Utility::iGet(Data::AActorList[i].Address + 800);
//		DWORD bodyAddv = tmpAddv + 336;
//		DWORD boneAddv = Utility::iGet(tmpAddv + 0x5b0) + 48;
//
//		VECTOR2 chest;
//		VECTOR2 head;
//		VECTOR3 chestPos = Data::AActorList[i].HeadPos;//  Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);
//		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
//		{
//			if (Setting::fovcircle)
//			{
//				if (InsideFov(DX11Window::Width, DX11Window::Height, chest, Setting::fovcircleredus/*FovRadius*/))
//				{
//					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));
//					if (cross_dist < targetDistance)
//					{
//						ret = chest;
//						targetDistance = cross_dist;
//
//					}
//				}
//			}
//			else
//			{
//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
//				{
//					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));
//
//					if (cross_dist < targetDistance)
//					{
//						ret = chest;
//						targetDistance = cross_dist;
//
//					}
//				}
//			}
//		}
//	}
//	return ret;
//}
//
//VOID Aimbot::AimbotThread()
//{
//	INT Num = 0;
//	INT Num2 = 0;
//	//	FLOAT Setting::Aimspeed = 0;
//	FLOAT Num4 = 0;
//	FLOAT Num5 = 0;
//
//	VECTOR2 Head;
//	Head.X = 0;
//	Head.Y = 0;
//	FLOAT X = 0;
//	FLOAT Y = 0;
//
//	while (true)
//	{
//		VECTOR2 MagicCoordinate;
//		//Sleep(10);
//		if (Setting::Aimbot)
//		{
//			if (Setting::engine == 0)
//			{
//
//				if ((GetAsyncKeyState(Setting::AimbotKey) & 0x8000)) // Left Mouse button
//				{
//					Head = GetClosestEnemy();
//					if ((Head.X > 0 && Head.Y > 0))
//					{
//						Num = DX11Window::Width / 2;
//						Num2 = DX11Window::Height / 2;
//						//Setting::Aimspeed = 11;  // Aim speed
//						Num4 = 0.0f;
//						Num5 = 0.0f;
//
//						X = Head.X;
//						Y = Head.Y;
//
//						if (X > 0)
//						{
//							if (X > (float)Num)
//							{
//								Num4 = -((float)Num - X);
//								Num4 /= Setting::Aimspeed;
//								if (Num4 + (float)Num > (float)(Num * 2))
//								{
//									Num4 = 0.0f;
//								}
//							}
//
//							if (X < (float)Num)
//							{
//								Num4 = X - (float)Num;
//								Num4 /= Setting::Aimspeed;
//								if (Num4 + (float)Num < 0.0f)
//								{
//									Num4 = 0.0f;
//								}
//							}
//						}
//
//						if (Y > 0)
//						{
//							if (Y > (float)Num2)
//							{
//								Num5 = -((float)Num2 - Y);
//								Num5 /= Setting::Aimspeed;
//								if (Num5 + (float)Num2 > (float)(Num2 * 2))
//								{
//									Num5 = 0.0f;
//								}
//							}
//
//							if (Y < (float)Num2)
//							{
//								Num5 = Y - (float)Num2;
//								Num5 /= Setting::Aimspeed;
//								if (Num5 + (float)Num2 < 0.0f)
//								{
//									Num5 = 0.0f;
//								}
//							}
//						}
//
//						mouse_event(1U, (int)Num4, (int)Num5, NULL, NULL);
//					}
//				}
//			}
//
//
//			if (Setting::engine == 1)
//			{
//				Setting::MagicBullet = true;
//
//			}
//
//		}
//
//		std::this_thread::sleep_for(std::chrono::milliseconds(40));
//	}
//}



#include "Aimbot.h"
#include"Memory.h"
#include<thread>


bool Aimbot::InsideFov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius)
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



VECTOR2 Aimbot::GetClosestEnemy()
{

	float targetDistance = 9999.0;
	VECTOR2 retval;
	int dist, headdist;
	VECTOR2 ret;
	for (int i = 0; i < Data::AActorList.size(); i++) {
		DWORD tmpAddv = Utility::ReadMemoryEx<int>(Data::AActorList[i].Address + 800);
		DWORD bodyAddv = tmpAddv + 336;
		DWORD boneAddv = Utility::ReadMemoryEx<int>(tmpAddv + 0x5b0) + 48;

		VECTOR2 chest;
		VECTOR2 head;
		VECTOR3 chestPos = Data::AActorList[i].HeadPos;//  Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
		{
			if (Settings::Fovbased)
			{
				if (InsideFov(DX11Window::Width, DX11Window::Height, chest, Settings::fovcircleredus/*FovRadius*/))
				{
					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));
					if (cross_dist < targetDistance)
					{
						ret = chest;
						targetDistance = cross_dist;

					}
				}
			}
			else
			{
				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
				{
					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));

					if (cross_dist < targetDistance)
					{
						ret = chest;
						targetDistance = cross_dist;

					}
				}
			}
		}
	}
	return ret;
}



VOID Aimbot::AimbotThread()
{
	INT Num = 0;
	INT Num2 = 0;
	//	FLOAT Setting::Aimspeed = 0;
	FLOAT Num4 = 0;
	FLOAT Num5 = 0;
	VECTOR2 MagicCoordinate;

	VECTOR2 Head;
	Head.X = 0;
	Head.Y = 0;
	FLOAT X = 0;
	FLOAT Y = 0;

	while (true)
	{

		//Sleep(10);
		if (Settings::AimBot)
		{
			if (Data::AActorList.size() != 0)
			{

				if ((GetAsyncKeyState(Settings::AimKey) & 0x8000)) // Left Mouse button
				{
					Head = GetClosestEnemy();
					if ((Head.X > 0 && Head.Y > 0))
					{
						Num = DX11Window::Width / 2;
						Num2 = DX11Window::Height / 2;
						//Setting::Aimspeed = 11;  // Aim speed
						Num4 = 0.0f;
						Num5 = 0.0f;

						X = Head.X;
						Y = Head.Y;

						if (X > 0)
						{
							if (X > (float)Num)
							{
								Num4 = -((float)Num - X);
								Num4 /= Settings::AimSpeed;
								if (Num4 + (float)Num > (float)(Num * 2))
								{
									Num4 = 0.0f;
								}
							}

							if (X < (float)Num)
							{
								Num4 = X - (float)Num;
								Num4 /= Settings::AimSpeed;
								if (Num4 + (float)Num < 0.0f)
								{
									Num4 = 0.0f;
								}
							}
						}

						if (Y > 0)
						{
							if (Y > (float)Num2)
							{
								Num5 = -((float)Num2 - Y);
								Num5 /= Settings::AimSpeed;
								if (Num5 + (float)Num2 > (float)(Num2 * 2))
								{
									Num5 = 0.0f;
								}
							}

							if (Y < (float)Num2)
							{
								Num5 = Y - (float)Num2;
								Num5 /= Settings::AimSpeed;
								if (Num5 + (float)Num2 < 0.0f)
								{
									Num5 = 0.0f;
								}
							}
						}

						mouse_event(1U, (int)Num4, (int)Num5, NULL, NULL);
					}
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}