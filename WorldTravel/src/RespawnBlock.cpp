#include "RespawnBlock.h"
#include <fstream>  
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>

namespace respawnblock
{

	void BlockSARespawns()
	{
		if (!NETWORK::NETWORK_IS_IN_SESSION())
		{
			if (!worldtravel::IsLosSantos() && worldtravel::RespawnBlockToggle::GetRespawnBlock())
			{
				GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME((char*)"respawn_controller");

				for (int i = 0; i < 5; i++)
				{
					GAMEPLAY::DISABLE_HOSPITAL_RESTART(i, true);
				}
				for (int i = 0; i < 7; i++)
				{
					GAMEPLAY::DISABLE_POLICE_RESTART(i, true);
				}
			}
		}
	}

	void RespawnBlockMain()
	{
		while (true)
		{
			BlockSARespawns();
			WAIT(0);
		}
	}
}

void RespawnBlock()
{
	srand(GetTickCount());
	respawnblock::RespawnBlockMain();
}