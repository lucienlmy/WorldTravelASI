#pragma once


#include <string>
#include "..\dependencies\include\natives.h"


class IPL
{
public: 
	std::string iplName;
	bool iplState;

	IPL(std::string ipl);

	void RequestIPL(bool checkState);
	void RemoveIPL(bool saveState);
	void SetIPLState();
	void SetIPLState(bool state);
	bool GetIPLState();
};
