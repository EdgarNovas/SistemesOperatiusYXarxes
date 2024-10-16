#pragma once
#include <mutex>
#include <chrono>
#include <functional>
#include <windows.h>

class Timer
{
	typedef std::function<void> OnTimeElapsed();
public:
	void StartTimer(unsigned long timeRequiredMiliseconds,OnTimeElapsed onTimeElapsed)
	{
		std::thread* thread = new std::thread([timeRequiredMiliseconds, onTimeElapsed]() {
			Sleep(timeRequiredMiliseconds);
				
		});
		thread->detach();
	}
};
