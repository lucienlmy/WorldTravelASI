#include "Scenario.h"
namespace objects
{
	namespace map
	{
		class Scenario
		{
			std::string scenarioName;
			bool scenarioState;

			Scenario(std::string scenario)
			{
				scenarioName = scenario;
				scenarioState = true;
			}

			std::string GetScenarioName()
			{
				return scenarioName;
			}

			void RequestScenario(bool checkState)
			{
				if (checkState)
				{
					if (!scenarioState)
					{
						return;
					}
				}
				AI::SET_SCENARIO_GROUP_ENABLED((char*)scenarioName.c_str(), true);
			}

			void RemoveScenario(bool saveState)
			{
				if (saveState)
					SetScenarioState();
				AI::SET_SCENARIO_GROUP_ENABLED((char*)scenarioName.c_str(), false);
			}

			void SetScenarioState()
			{
				scenarioState = AI::IS_SCENARIO_GROUP_ENABLED((char*)scenarioName.c_str());
			}

			void SetScenarioState(bool state)
			{
				scenarioState = state;
			}

			bool GetScenarioState()
			{
				return scenarioState;
			}
		};
	}
}