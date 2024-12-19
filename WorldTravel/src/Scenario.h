#pragma once

#include <string>
#include "..\dependencies\include\natives.h"

class Scenario
{
public:
	std::string scenarioName;
	bool scenarioState;

	Scenario(std::string scenario);

	void RequestScenario(bool checkState);
	void RemoveScenario(bool saveState);
	void SetScenarioState();
	void SetScenarioState(bool state);
	bool GetScenarioState();
};