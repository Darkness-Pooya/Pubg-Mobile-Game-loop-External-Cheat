#pragma once
#pragma once

#include "Includes.h"
#include "Algorithm\Algorithm.h"
#include "Utility\Utility.h"
#include "Data\Data.h"
#include "Esp\Esp.h"
void legit();

namespace Memory
{
	extern	bool IsMagicInitialized;// = false;
	VOID MemoryThread();

	int AimFindBestTarget();
	VECTOR2 GetMagicCoordinate();
	VOID RestoreHook();
	void AllMemoryHacks();
	void DoModSkin();
}
