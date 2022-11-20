#include <chrono>
#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>

const long limitNumber = 600851475143;

std::function<bool(int)> dividesLimit = [limitNumber] (long n) 
{
    if (limitNumber % n == 0) 
    {
        return true;
    }
    return false;
};

long maxPrimeUsingSieve (long n, std::function<bool(long)> filter) 
{
    std::vector<unsigned char> sieve;
    sieve.resize(n + 1);
    memset(sieve.data(), 0, (n + 1) * sizeof(unsigned char));
    for (long i = 2; i < int(sqrt(n)); i++) 
    {
        if (sieve[i] != 0) 
        {
            continue;
        }
        for (long j = i + i; j < n; j += i) 
        {
            sieve[j] = (unsigned short) 1;
        }
    }
    for (long i = n - 1; i >= 2; i--) 
    {
        if (sieve[i] != 0)
        {
            continue;
        }
        if (filter(i))
        {
            return i;
        }
    }
    return (long) 1;
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long prime = maxPrimeUsingSieve(int(sqrt(limitNumber)), dividesLimit);
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << prime << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
