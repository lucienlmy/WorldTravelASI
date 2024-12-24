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


		uint8_t* maxRadioStations2 = hook::get_pattern<uint8_t>("BD 60 00 00 00", 1);
		VirtualProtect(maxRadioStations2, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*maxRadioStations2 = 255;
		VirtualProtect(maxRadioStations2, 1, oldProtect, &oldProtect);
		uint32_t* radioStationsMemSize2 = (uint32_t*)(maxRadioStations2 + 0x43);
		VirtualProtect(radioStationsMemSize2, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
		*radioStationsMemSize2 = 255 * 8;
		VirtualProtect(radioStationsMemSize2, 4, oldProtect, &oldProtect);


		uint8_t* maxRadioStations3 = hook::get_pattern<uint8_t>("45 8D 67 ? 8B C6", 2);
		VirtualProtect(maxRadioStations3, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
		*maxRadioStations3 = 255;
		VirtualProtect(maxRadioStations3, 1, oldProtect, &oldProtect);
		uint32_t* radioStationsMemSize3 = (uint32_t*)(maxRadioStations3 + 0x143);
		VirtualProtect(radioStationsMemSize3, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
		*radioStationsMemSize3 = 255 * 8;
		VirtualProtect(radioStationsMemSize3, 4, oldProtect, &oldProtect);
	}
};