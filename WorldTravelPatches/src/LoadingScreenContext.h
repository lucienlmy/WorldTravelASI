#pragma once
#include "Hooking.h"
#include "Hooking.Patterns.h"
#include <assert.h>
static uintptr_t g_LoadingScreenContextAdd;

typedef void(__fastcall* _shutdown)();
static _shutdown f_Shutdown;

namespace CLoadingScreens
{
	enum LoadingScreenContext
	{
		LOADINGSCREEN_CONTEXT_NONE = 0,
		LOADINGSCREEN_CONTEXT_INTRO_MOVIE = 1,
		LOADINGSCREEN_CONTEXT_LEGALSPLASH = 2,
		LOADINGSCREEN_CONTEXT_LEGALMAIN = 3,
		LOADINGSCREEN_CONTEXT_SWAP = 4,
		LOADINGSCREEN_CONTEXT_PC_LANDING = 5,
		LOADINGSCREEN_CONTEXT_LOADGAME = 6,
		LOADINGSCREEN_CONTEXT_INSTALL = 7,
		LOADINGSCREEN_CONTEXT_LOADLEVEL = 8,
		LOADINGSCREEN_CONTEXT_MAPCHANGE = 9,
		LOADINGSCREEN_CONTEXT_LAST_FRAME = 10,
	};
	static void Shutdown()
	{
		static void(*fn)() = (decltype(fn))hook::get_pattern("40 57 48 83 EC 20 8B 05 ? ? ? ? 85 C0 0F 84 ? ? ? ? 83 F8 06 74");
		fn();
	}
	static LoadingScreenContext GetLoadingScreenContext()
	{

		return *(LoadingScreenContext*)g_LoadingScreenContextAdd;
	}
	static void SetLoadingScreenContext(LoadingScreenContext context)
	{
		if (!g_LoadingScreenContextAdd)
		{
			GetLoadingScreenContext();
		}
		*(LoadingScreenContext*)g_LoadingScreenContextAdd = context;
	}
	static std::string LoadingScreenContextToString(LoadingScreenContext& context)
	{
		switch (context)
		{
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_NONE:
			return "NONE";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_INTRO_MOVIE:
			return "LOADINGSCREEN_CONTEXT_INTRO_MOVIE";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_LEGALSPLASH:
			return "LOADINGSCREEN_CONTEXT_LEGALSPLASH";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_LEGALMAIN:
			return "LOADINGSCREEN_CONTEXT_LEGALMAIN";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_SWAP:
			return "LOADINGSCREEN_CONTEXT_SWAP";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_PC_LANDING:
			return "LOADINGSCREEN_CONTEXT_PC_LANDING";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_LOADGAME:
			return "LOADINGSCREEN_CONTEXT_LOADGAME";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_INSTALL:
			return "LOADINGSCREEN_CONTEXT_INSTALL";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_LOADLEVEL:
			return "LOADINGSCREEN_CONTEXT_LOADLEVEL";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_MAPCHANGE:
			return "LOADINGSCREEN_CONTEXT_MAPCHANGE";
		case CLoadingScreens::LOADINGSCREEN_CONTEXT_LAST_FRAME:
			return "LOADINGSCREEN_CONTEXT_LAST_FRAME";
		default:
			return "UNKNOWN_LOADINGSCREEN_STATE";
		}
	}
	uintptr_t FindAddressOffset(uintptr_t address)
	{
		int* offset = (int*)(address); //offset of addr can be found from start of func ad + 33 bytes
		uintptr_t RIP = address + 4; //address of next instruction from which the offset is calculated from
		return RIP + *(offset);
	}
	static void Hook()
	{
		//MessageBoxA(0, "", "", 0);
		g_LoadingScreenContextAdd = FindAddressOffset((uintptr_t)hook::get_pattern("33 D2 48 8D 45 10 39 15")+8); 
		assert(g_LoadingScreenContextAdd != NULL);
		f_Shutdown = (_shutdown)hook::get_pattern("40 57 48 83 EC 20 8B 05 ? ? ? ? 85 C0 0F 84 ? ? ? ? 83 F8 06 74 08 83 C0 F8 83 F8 02");
		//std::cout << "f_shutdown: " << std::hex << &f_Shutdown << std::endl;
		assert(f_Shutdown != NULL);
	}

}
