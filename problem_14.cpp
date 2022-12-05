#include <chrono>
#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <cmath>

const int maxStarter = 1000000;

long nextCollatz (long i) 
{
    switch (i % 2)
    {
        case 0:
        return i / 2;
        break;
        case 1:
        default:
        return 3 * i + 1;
    }
}


int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    std::array<int, maxStarter> accCollatz;
    int* pCollatz = accCollatz.data();
    memset(pCollatz, 0, maxStarter*sizeof(int));
    int longestSequence = 0;
    int longestSequenceNum = 0;
    int filledAccCollatz = 1;

    for (long i = 1; i < maxStarter && filledAccCollatz < maxStarter; i++) 
    {
        if (pCollatz[i])
        {
            continue;
        }
        pCollatz[i] = 1;
        filledAccCollatz++;
        long cur = i;
        int curSequence = 0;
        while (cur != 1)
        {
            cur = nextCollatz(cur);
            curSequence++;
            if (cur > 1 && cur < maxStarter && !pCollatz[i])
            {
                pCollatz[i] = 1;
                filledAccCollatz++;
            }
        }
        if (curSequence > longestSequence) 
        {
            longestSequence = curSequence;
            longestSequenceNum = i; 
        }
    }

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Sequence length: " << longestSequence << std::endl;
    std::cout << "Solution: " << longestSequenceNum << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
