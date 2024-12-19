#pragma once
#include <vector>
#include <functional>

namespace events
{
	class Event
	{
		using Callback = std::function<void(void)>;

	private:
		std::vector<Callback> m_Callbacks;

	public:
		void Add(const Callback& cb);
		void Raise();
	};

	void InstallEvents();

	extern Event OnCorePreUpdate;
}

