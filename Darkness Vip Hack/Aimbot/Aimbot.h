#pragma once

#include "Includes.h"
#include "Algorithm\Algorithm.h"
#include "Data\Data.h"
#include "Esp\Esp.h"
#include "Settings\Settings.h"
#include<thread>
namespace Aimbot
{
	VECTOR2 GetClosestEnemy();
	VOID AimbotThread();
	bool InsideFov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius);
}
