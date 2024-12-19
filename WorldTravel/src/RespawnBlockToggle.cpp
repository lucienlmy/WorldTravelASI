#include "RespawnBlockToggle.h"

namespace worldtravel
{
	namespace RespawnBlockToggle
	{
		bool blockRespawn = false;
		void SetRespawnBlock(bool block)
		{
			blockRespawn = block;
		}
		bool GetRespawnBlock()
		{
			return blockRespawn;
		}
	}
}