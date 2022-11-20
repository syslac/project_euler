#include <chrono>
#include <iostream>

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long mcm = 16 * 9 * 5 * 7 * 11 * 13 * 17 * 19;

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << mcm << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
