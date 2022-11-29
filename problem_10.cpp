#include <chrono>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <functional>

const long limitNumber = 2000000;

std::function<long(long, long)> sum = [] (long n, long m) 
{
    return n + m;
};

long reducePrimesUsingSieve (long n, std::function<long(long, long)> reduceFunc, long acc) 
{
    std::vector<unsigned char> sieve;
    sieve.resize(n + 1);
    memset(sieve.data(), 0, (n + 1) * sizeof(unsigned char));
    for (long i = 2; i <= int(sqrt(n)); i++) 
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
    for (long i = 2; i < n; i++) 
    {
        if (sieve[i] == 0)
        {
            acc = reduceFunc(acc, i);
        }
    }
    return acc;
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long sumOfPrimes = reducePrimesUsingSieve(limitNumber, sum, 0);
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << sumOfPrimes << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
