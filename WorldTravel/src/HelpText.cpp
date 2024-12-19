#include "HelpText.h"

namespace worldtravel
{
	namespace HelpText
	{
		void DisplayHelpText(std::string text)
		{
			UI::BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text.c_str());
			UI::END_TEXT_COMMAND_DISPLAY_HELP(0, 0, 1, -1);
		}
	}
}