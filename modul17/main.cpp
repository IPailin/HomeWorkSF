#include <iostream>
#include <chrono>

#include "Timer.h"

int  main(int argc, char *argv[])
{
    long long size_arr = 100000;
    long long arr_number[size_arr];

    Timer t;

    for(long long i = 0; i < size_arr; i++){
       arr_number[i] = 1 + rand() % 20;
    }

    std::cout << "time = " << t.elapsed() << std::endl;

    t.reset();

    for(long long i = 0; i < size_arr; ++i){
        arr_number[i] = (1 + rand() % 20) * 2;
    }

    std::cout << "time = " << t.elapsed() << std::endl;
    return 0;
}