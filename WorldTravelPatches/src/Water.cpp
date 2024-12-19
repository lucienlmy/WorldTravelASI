#include "Water.h"
#include "UsingAllocator.h"
#include "Hooking.Patterns.h"
#include "Hooking.h"
#include "Hashing.h"
#include <MinHook.h>
#include "spdlog/spdlog.h"
#include "CDataFileMgr.h"
#include "CPathFind.h"
#include <filesystem>
#include "Events.h"
#include "CWaterData.h"

namespace patches {
namespace water {

static bool wantToLoadWaterData = false;
static char waterDataFileToLoad[512];
static unsigned int* gameState = nullptr;
static unsigned int prevGameState = 0xFFFFFFFF;

typedef void(*tCWaterData_Unload)();
typedef void(*tCWaterData_Load)(const char* path);

static tCWaterData_Unload fCWaterData_Unload = nullptr;
static tCWaterData_Load fCWaterData_Load = nullptr;

static void CheckForLoading()
{
	if (wantToLoadWaterData)
	{
		fCWaterData_Unload();
		fCWaterData_Load(waterDataFileToLoad);

		wantToLoadWaterData = false;
		waterDataFileToLoad[0] = 0;
	}
}

void Init()
{
	uintptr_t callingAddress = (uintptr_t)hook::get_pattern("E8 ? ? ? ? 83 0D ? ? ? ? ? 40 88 2D"); // Water::FlipBuffers, calling Water::LoadGlobalWaterXmlFile
	uintptr_t origSwitchWaterAddr = hook::get_call<uintptr_t>(callingAddress);

	CDataFileMgr::sm_Instance = hook::get_address<CDataFileMgr**>(origSwitchWaterAddr + 0x97, 3, 7);

	CWaterData::curLoadedArea = hook::get_address<eWaterArea*>(origSwitchWaterAddr + 0x0E, 2, 6);
	CWaterData::bd_min_x = hook::get_address<int32_t*>(origSwitchWaterAddr + 0x29, 2, 6);
	CWaterData::bd_min_y = hook::get_address<int32_t*>(origSwitchWaterAddr + 0x2F, 2, 6);
	CWaterData::bd_max_x = hook::get_address<int32_t*>(origSwitchWaterAddr + 0x1F, 2, 10);
	CWaterData::bd_max_y = hook::get_address<int32_t*>(origSwitchWaterAddr + 0x35, 2, 10);

	intptr_t allocatedFunctionAddress = (intptr_t)hook::AllocateFunctionStub((void*)origSwitchWaterAddr, CWaterData::switchWater, 0);
	int32_t offset = static_cast<int32_t>(allocatedFunctionAddress - (callingAddress + 5));
	hook::put<int32_t>(callingAddress + 1, offset);
}

void Load(const char* filePath)
{
	strcpy_s(waterDataFileToLoad, filePath);
	wantToLoadWaterData = true;
}

void BeginLoadScreen()
{
	prevGameState = *gameState;
	*gameState = 2;
}

void EndLoadScreen()
{
	*gameState = prevGameState;
	prevGameState = 0xFFFFFFFF;
}

} }