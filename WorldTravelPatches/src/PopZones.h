#pragma once
#include <cstdint>
#include <string>
#include "Hooking.Patterns.h"
#include <MinHook.h>
#include "Hooking.h"

class PopZones
{
public:
	/// <summary>
	/// Patches the allowed amount of zones, allowing for both Los Santos and Liberty City zones.
	/// </summary>
	static void GetZonePopSchedulePatch()
	{
		uint8_t* addr = hook::get_pattern<uint8_t>("E8 ? ? ? ? 0F BE 40 06 EB 09 E8 ? ? ? ? 0F BE 40 05"); // zone_commands::CommandGetZonePopSchedule
		DWORD oldProtect;
		VirtualProtect(addr + 6, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*(addr + 6) = 0xB6;
		VirtualProtect(addr + 6, 1, oldProtect, &oldProtect);

		VirtualProtect(addr + 17, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*(addr + 17) = 0xB6;
		VirtualProtect(addr + 17, 1, oldProtect, &oldProtect);
	}
	/// <summary>
	/// Patches the allowed amount of zones, allowing for both Los Santos and Liberty City zones.
	/// </summary>
	static void UpdateCurrentZoneFromCoordsPatch()
	{
		uint8_t* addr = hook::get_pattern<uint8_t>("0F BE 54 88 ? EB 5F 41 B8 ? ? ? ? E8"); // CPopCycle::UpdateCurrZoneFromCoors
		DWORD oldProtect;
		VirtualProtect(addr + 1, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*(addr + 1) = 0xB6;
		VirtualProtect(addr + 1, 1, oldProtect, &oldProtect);
	}

	/// <summary>
	/// Patches the allowed amount of zones, allowing for both Los Santos and Liberty City zones.
	/// </summary>
	static void UpdateCurrentZoneFromCoords2Patch()
	{
		uint8_t* addr = hook::get_pattern<uint8_t>("0F BE 54 88 ? EB 02 8B D3 89 15"); // CPopCycle::UpdateCurrZoneFromCoors
		DWORD oldProtect;
		VirtualProtect(addr + 1, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*(addr + 1) = 0xB6;
		VirtualProtect(addr + 1, 1, oldProtect, &oldProtect);
	}
};