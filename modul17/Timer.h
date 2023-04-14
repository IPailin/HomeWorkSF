#include <iostream>
#include <chrono>

class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> beg_time;

public:
    Timer() : beg_time(std::chrono::high_resolution_clock::now())
	{
    }

    ~Timer() = default;

    void reset();

    double elapsed();
};