#include "PlayerObjects.h"

namespace worldtravel
{
	namespace PlayerObjects
	{

		void SetPlayerObjects()
		{
			playerPed = PLAYER::PLAYER_ID();
			playerPed = PLAYER::PLAYER_PED_ID();
			bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
		}

		Ped GetPlayerObjects()
		{
			return playerPed;
		}
	}
}