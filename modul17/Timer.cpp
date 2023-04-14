#include "Timer.h"

void Timer::reset()
{
    beg_time = std::chrono::high_resolution_clock::now();
}
	
double Timer::elapsed()
{	
	auto now_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_sec = (now_time - beg_time);

	return elapsed_sec.count();
}