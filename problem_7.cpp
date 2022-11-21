#include <chrono>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

const long limitNumber = 120000;
const int soughtPrime = 10001;

std::vector<long> primes;

std::vector<long>* allPrimesUsingSieve (long n) 
{
    std::vector<unsigned char> sieve;
    if (primes.size() > 0) 
    {
        primes.resize(0);
    }
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
    for (long i = 2; i <= n; i++) 
    {
        if (sieve[i] == 0)
        {
            primes.push_back(i);
        }
    }
    return &primes;
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long prime = 0;
    std::vector<long>* primes = allPrimesUsingSieve(limitNumber);
    if (primes->size() >= soughtPrime) 
    {
        prime = primes->at(soughtPrime - 1);
    }
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << prime << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
