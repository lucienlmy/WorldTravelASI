#include "CDataFileMgr.h"
#include "Hooking.Patterns.h"

CDataFileMgr* CDataFileMgr::Instance()
{
	static CDataFileMgr** inst = []() 
	{
		auto addr = hook::get_pattern<uint8_t>("48 8B 0D ? ? ? ? E8 ? ? ? ? EB 2F"); // CFileLoader::AddAllRpfFiles
		return (CDataFileMgr**)(addr + *(int*)(addr + 3) + 7);
	}();

	return *inst;
}

void CFileLoader::EnableRpfFile(CDataFileMgr::DataFile* fileEntry)
{
	static void(*fn)(CDataFileMgr::DataFile*) = (decltype(fn))hook::get_pattern("48 89 5C 24 ? 57 48 83 EC 20 80 B9 ? ? ? ? ? 48 8B F9 74 59"); // CFileLoader::ChangeSetAction_LoadRPF

	fn(fileEntry);
}

void CFileLoader::DisableRpfFile(CDataFileMgr::DataFile* fileEntry)
{
	static void(*fn)(CDataFileMgr::DataFile*) = (decltype(fn))hook::get_pattern("48 89 5C 24 ? 57 48 81 EC ? ? ? ? 80 B9 ? ? ? ? ? 48 8B F9 0F 85"); // CFileLoader::ChangeSetAction_UnloadRPF

	fn(fileEntry);
}