#include <iostream>
#include <thread>
#include <mutex>
#include "../include/thread_utils.h"

std::mutex mtx;

#define LOCK_MUTEX() std::lock_guard<std::mutex> lock(mtx)

void printRange(int start, int end) 
{
    LOCK_MUTEX();
    for (int i = start; i <= end; ++i)
    {
        std::cout << i << "\n";
    }
}

int main() 
{
    std::thread t1(printRange, 1, 5);
    std::thread t2(printRange, 6, 10);

    t1.join();
    t2.join();

    return 0;
}

//CNTRL+SHIFT+B to build the project. This code creates two threads that print numbers from 1 to 5 and from 6 to 10, respectively. The mutex ensures that the output is not interleaved, providing a clear and organized display of the numbers.
//Press F5 to run the project after building. You should see the numbers from 1 to 10 printed in order, without any interleaving, due to the use of the mutex to synchronize access to the output stream.
