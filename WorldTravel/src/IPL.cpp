#include "IPL.h"

namespace objects
{
	namespace map
	{
		class IPL
		{
			std::string iplName;
			bool iplState;

			IPL(std::string ipl)
			{
				iplName = ipl;
				iplState = true;
			}

			std::string GetIPLName()
			{
				return iplName;
			}

			void RequestIPL(bool checkState)
			{
				if (checkState)
				{
					if (!iplState)
					{
						return;
					}
				}
				STREAMING::REQUEST_IPL((char*)iplName.c_str());
			}

			void RemoveIPL(bool saveState)
			{
				if (saveState)
					SetIPLState();
				STREAMING::REMOVE_IPL((char*)iplName.c_str());
			}

			void SetIPLState()
			{
				iplState = STREAMING::IS_IPL_ACTIVE((char*)iplName.c_str());
			}

			void SetIPLState(bool state)
			{
				iplState = state;
			}

			bool GetIPLState()
			{
				return iplState;
			}
		};
	}
}