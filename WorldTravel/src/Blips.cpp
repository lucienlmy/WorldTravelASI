#include "Blips.h"

namespace worldtravel
{
	namespace Blips
	{
		void CreateBlip(Blip& RadarBlip, float x, float y, float z, int scale, int sprite, std::string label, int color, bool flashes, int display, bool shortRange, int category)
		{
			RadarBlip = UI::ADD_BLIP_FOR_COORD(x, y, z);
			UI::SET_BLIP_SCALE(RadarBlip, static_cast<float>(scale));
			UI::SET_BLIP_SPRITE(RadarBlip, sprite);
			UI::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)label.c_str());
			UI::END_TEXT_COMMAND_SET_BLIP_NAME(RadarBlip);
			UI::SET_BLIP_COLOUR(RadarBlip, color);
			UI::SET_BLIP_FLASHES(RadarBlip, flashes);
			UI::SET_BLIP_DISPLAY(RadarBlip, display);
			UI::SET_BLIP_AS_SHORT_RANGE(RadarBlip, shortRange);
			UI::SET_BLIP_CATEGORY(RadarBlip, category);
		}

		void MoveBlip(Blip& RadarBlip, float x, float y, float z)
		{
			UI::SET_BLIP_COORDS(RadarBlip, x, y, z);
		}

		void RelableBlip(Blip& RadarBlip, std::string label)
		{
			UI::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)label.c_str());
			UI::END_TEXT_COMMAND_SET_BLIP_NAME(RadarBlip);
		}

		void SetBlipDisplay(Blip& RadarBlip, int display)
		{
			if (UI::DOES_BLIP_EXIST(RadarBlip))
				UI::SET_BLIP_DISPLAY(RadarBlip, display);
		}
	}
}