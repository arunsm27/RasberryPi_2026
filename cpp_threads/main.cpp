#include <iostream>
#include <thread>
#include <mutex>

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

//CNTRL+SHIFT+B to 
