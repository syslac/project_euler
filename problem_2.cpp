#include <chrono>
#include <iostream>
#include <vector>

const long long limitNumber = 4000000;

class Fibonacci 
{
    std::vector<long> fibCache;
    const int cachePresizing = 100;

    public:
    Fibonacci() 
    {
        fibCache.resize(cachePresizing);
	for (int i = 0; i < cachePresizing; i++) 
	{
            fibCache[i] = 0; 
	}
    }

    ~Fibonacci() 
    {
        fibCache.resize(0);
    }

    long fib(int n)
    {
        if (n <= 1) 
        {
            fibCache[n] = long(1);
            return long(1);
        }
	if (fibCache[n] != 0) 
	{
            return fibCache[n];
	}
	long prev2 = (fibCache[n - 2] != 0) ? fibCache[n - 2] : fib(n - 2);
	long prev1 = (fibCache[n - 1] != 0) ? fibCache[n - 1] : fib(n - 1);
	fibCache[n] = prev2 + prev1;
	return prev2 + prev1;
    }
};


int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();
    
    Fibonacci computeFib;
    long long runningSum = 0;
    int i = 0;
    int curFib = 0;
    do {
        curFib = computeFib.fib(i);
	if (curFib % 2 == 0) 
	{
	    runningSum += curFib;
	}
	i++;
    }
    while (curFib < limitNumber);

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << runningSum << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
