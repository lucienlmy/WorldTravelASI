#pragma once
#include <cstdint>
#include <string>
#include "Hooking.Patterns.h"
#include <MinHook.h>
#include "Hooking.h"

class RadioStations
{
public:
	static void Patch()
	{
		uint8_t* maxRadioStations = hook::get_pattern<uint8_t>("8D 5E 60 89 35", 2); // audRadioStation::InitClass
		DWORD oldProtect;
		VirtualProtect(maxRadioStations, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*maxRadioStations = 255;
		VirtualProtect(maxRadioStations, 1, oldProtect, &oldProtect);
		uint32_t* radioStationsMemSize = (uint32_t*)(maxRadioStations + 0x26);
		VirtualProtect(radioStationsMemSize, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
		*radioStationsMemSize = 255 * 8;
		VirtualProtect(radioStationsMemSize, 4, oldProtect, &oldProtect);
	}
};