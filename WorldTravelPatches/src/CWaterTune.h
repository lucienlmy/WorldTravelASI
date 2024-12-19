#pragma once
#include "CDataFileMgr.h"
#include "Hooking.Patterns.h"

class CWaterTune
{
public:
	static inline void load(char* path)
	{
		//48 83 EC 38 48 85 C9 48 8D 15
		static void(*fn)(char* path) = (decltype(fn))hook::get_pattern("48 83 EC 38 48 85 C9 48 8D 15"); // LoadWaterTunings

		fn(path);
	}
	static inline void loadWaterFog()
	{
		//48 89 5C 24 ? 55 56 57 41 56 41 57 48 8B EC 48 83 EC 40 8B 0D
		static void(*fn)() = (decltype(fn))hook::get_pattern("48 89 5C 24 ? 55 56 57 41 56 41 57 48 8B EC 48 83 EC 40 8B 0D"); // Water::InitFogTextureTxdSlots

		fn();
	}
	static inline char* GetFirstFile(CDataFileMgr* fileMgr, int size)
	{
		//83 4D 4B FF 45 33 F6 48 8B F9 8B DA 48 8D 4D A7 41 B8
		static char* (*fn)(CDataFileMgr * fileMgr, int size) = (decltype(fn))hook::get_pattern("48 8B C4 48 89 58 08 48 89 78 10 4C 89 70 18 55 48 8D 68 A1 48 81 EC ? ? ? ? 83 4D 4B FF 45 33 F6 48 8B F9 8B DA 48 8D 4D A7 41 B8 ? ? ? ? 33 D2"); // CDataFileMgr::GetFirstFile

		return fn(fileMgr, size);
	}
	static inline int GetNextFile(CDataFileMgr* fileMgr)
	{
		//FF 25 ? ? ? ? F0 CF 
		static int(*fn)(CDataFileMgr * fileMgr) = (decltype(fn))hook::get_pattern("48 ? ? ? ? 0F B7 ? ? 44 8B 82"); // CDataFileMgr::GetNextFile

		return fn(fileMgr);
	}

};