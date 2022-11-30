#include <chrono>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <functional>

const long limitNumber = 1000000;
const int targetFactors = 500;

long triangular (long n) 
{
    return (n * (n + 1)) / 2;
}

void allPrimesUsingSieve (long n, std::vector<long>* primes) 
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
            primes->push_back(i);
        }
    }
}

void factorize(int n, std::vector<long>* primes, std::vector<int>* exponents)
{
    for (int i = 0; i < primes->size(); i++)
    {
        long curPrime = primes->at(i);
        if (curPrime > sqrt(n)) 
        {
            break;
        }
        int curExponent = 0;
        while (n % curPrime == 0 && curPrime <= n) 
        {
            curExponent++;
            curPrime *= primes->at(i);
        }
        exponents->at(i) = curExponent;
    }
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    std::vector<long> primes;
    allPrimesUsingSieve(limitNumber, &primes);
    std::vector<int> primeExponents;
    primeExponents.resize(primes.size());
    int numberOfFactors = 0;
    long candidate;
    int i = 0;
    while (numberOfFactors < targetFactors && i < limitNumber) 
    {
        memset(primeExponents.data(), 0, (primes.size()) * sizeof(int));
        candidate = triangular(i);
        factorize(candidate, &primes, &primeExponents);
        i++;
        numberOfFactors = 1;
        for (int j = 0; j < primes.size(); j++) 
        {  
            if (primes.at(j) > sqrt(candidate))
            {
                break;
            }
            numberOfFactors *= primeExponents.at(j) + 1;
        }
    }
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << candidate << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
