#include "Events.h"
#include <MinHook.h>
#include "Hooking.Patterns.h"

namespace events
{
	void Event::Add(const Event::Callback& cb)
	{
		m_Callbacks.push_back(cb);
	}

	void Event::Raise()
	{
		for (auto& cb : m_Callbacks)
		{
			cb();
		}
	}

	static void (*gameSkeleton_RunUpdate_orig)(void* skeleton, int type);
	static void gameSkeleton_RunUpdate_detour(void* skeleton, int type)
	{
		if (type == 1) // == Core
		{
			OnCorePreUpdate.Raise();
		}

		gameSkeleton_RunUpdate_orig(skeleton, type);
	}

	void InstallEvents()
	{
		MH_CreateHook(hook::get_pattern("40 53 48 83 EC 20 48 8B 81 ? ? ? ? 48 85 C0 74 2A"), gameSkeleton_RunUpdate_detour, (void**)& gameSkeleton_RunUpdate_orig); // rage::gameSkeleton::Update
	}

	Event OnCorePreUpdate;
}