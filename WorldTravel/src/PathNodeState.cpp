#include "PathNodeState.h"


namespace worldtravel {
	namespace PathNodeState {
		int state = 0;
		int GetPathNodeState()
		{
			return state;
		}
		void SetPathNodeState(int s)
		{
			if (s == 0)
			{
				PATHFIND::SET_ALLOW_STREAM_PROLOGUE_NODES(0);
				PATHFIND::SET_ALLOW_STREAM_HEIST_ISLAND_NODES(0);
			}
			else if (s == 1)
			{
				PATHFIND::SET_ALLOW_STREAM_HEIST_ISLAND_NODES(0);
				PATHFIND::SET_ALLOW_STREAM_PROLOGUE_NODES(1);
			}
			else if (s == 2)
			{
				PATHFIND::SET_ALLOW_STREAM_PROLOGUE_NODES(0);
				PATHFIND::SET_ALLOW_STREAM_HEIST_ISLAND_NODES(1);
			}
			state = s;
		}
	}
}