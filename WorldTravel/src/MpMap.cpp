#include "MpMap.h"
#include "PlayerLocation.h"

namespace worldtravel
{
	namespace MpMap
	{
		// Interior Coords
		float heist_police_dlc[] = { 442.4296f, -985.067f, 29.88529f };
		bool mpMapEnabled = false;

		bool IsMPMapActive()
		{
			return mpMapEnabled;
		}


		void CheckIfMPMapIsActive()
		{
			if (worldtravel::IsLosSantos())
			{
				if (INTERIOR::GET_INTERIOR_AT_COORDS(heist_police_dlc[0], heist_police_dlc[1], heist_police_dlc[2]) == 137473)
				{
					mpMapEnabled = true;
				}
				else
				{
					mpMapEnabled = false;
				}
			}
		}
	}
}