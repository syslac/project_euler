#include <chrono>
#include <iostream>

const int limitNr = 100;

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long runningDiff = 0;
    for (int i = 1; i <= limitNr; i++)
    {
        for (int j = i + 1; j <= limitNr; j++) 
        {
            runningDiff += 2 * i * j;
        }
    }

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << runningDiff << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
