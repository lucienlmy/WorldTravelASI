#include <Windows.h>
#include "Hooking.Patterns.h"
#include "GroupMap.h"
#include "Water.h"
#include "Paths.h"
#include "Settings.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <MinHook.h>
#include "CDataFileMgr.h"
#include "Events.h"
#include "Hooking.h"
#include "DecalLimits.h"
#include "RadioStations.h"
#include "PopZones.h"
#include "RockstarEditor.h"
#include "WeaponInfo.h"


DWORD WINAPI Main()
{
	Settings::Load();
	
	if (Settings::EnableLogging)
	{
		spdlog::set_default_logger(spdlog::basic_logger_mt("file_logger", "WorldTravelPatches.log"));
		spdlog::flush_every(std::chrono::seconds(5));
	}
	else
	{
		spdlog::set_level(spdlog::level::off);
	}

	spdlog::info("Main");

	MH_Initialize();

	events::InstallEvents();

	RadioStations::Patch();
	spdlog::info("Patched Radio Stations.");

	DecalLimits::PatchDecalLimits();
	spdlog::info("Patched Decal Limits.");
	DecalLimits::fwBoxStreamerVariablePatch();
	spdlog::info("Patched fwBoxStreamerVariable.");

	PopZones::GetZonePopSchedulePatch();
	PopZones::UpdateCurrentZoneFromCoordsPatch();
	PopZones::UpdateCurrentZoneFromCoords2Patch();
	spdlog::info("Patched PopZone / PopCycle.");

	RockstarEditor::Patch();
	spdlog::info("Patched Rockstar Editor.");
	//CWeaponInfo::PatchWeapons();
	//spdlog::info("Patched Weapon Limits.");
	patches::water::Init();
	spdlog::info("Patched Water.");

	MH_EnableHook(MH_ALL_HOOKS);
		
	spdlog::info("End");
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		Main();
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		spdlog::shutdown();
	}

	return TRUE;
}
