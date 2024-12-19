#include "RestrictedAreas.h"
#include <fstream>  
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>


namespace restrictedAreas
{
	//Prison Bound Coords
	std::vector<float> PrisonLowerBox1Min = { 4006.0f, -3750.0f, 0.0f };
	std::vector<float> PrisonLowerBox1Max = { 4158.0f, -3694.0f, 7.0f };

	std::vector<float> PrisonLowerBox2Min = { 4051.0f, -3714.0f, 0.0f };
	std::vector<float> PrisonLowerBox2Max = { 4289.0f, -3606.0f, 7.0f };

	std::vector<float> PrisonLowerBox3Min = { 4051.0f, -3606.0f, 0.0f };
	std::vector<float> PrisonLowerBox3Max = { 4245.0f, -3580.0f, 7.0f };

	std::vector<float> PrisonUpperBox1Min = { 4004.0f, -3757.0f, 7.0f };
	std::vector<float> PrisonUpperBox1Max = { 4160.0f, -3692.0f, 50.0f };

	std::vector<float> PrisonUpperBox2Min = { 4044.0f, -3714.0f, 7.0f };
	std::vector<float> PrisonUpperBox2Max = { 4293.0f, -3604.0f, 50.0f };

	std::vector<float> PrisonUpperBox3Min = { 4044.0f, -3606.0f, 7.0f };
	std::vector<float> PrisonUpperBox3Max = { 4249.0f, -3577.0f, 50.0f };



	//UN HQ Bound Coords
	std::vector<float> UNHQBox3Min = { 5325.34f, -2952.33f, 14.15f };
	std::vector<float> UNHQBox3Max = { 5430.27f, -2727.15f, 51.45f };

	bool isPlayerInRestrictedArea = false;

	bool RestrictedAreaBreached(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		if (ENTITY::IS_ENTITY_IN_AREA(playerPed, minX, minY, minZ, maxX, maxY, maxZ, false, false, false)
			|| GAMEPLAY::IS_PROJECTILE_IN_AREA(minX, minY, minZ, maxX, maxY, maxZ, true))
		{
			return true;
		}
		return false;
	}
}

void RestrictedAreas()
{ }