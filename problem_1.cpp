#include <chrono>
#include <iostream>

const int limitNumber = 1000;
const int block = 30;

bool useForSum(int n)
{
    const int numDividends = 2;
    int dividends[numDividends];
    dividends[0] = 3;
    dividends[1] = 5;
    for (int i = 0; i < numDividends; i++)
    {
       if (n % dividends[i] == 0)                   
       {
           return true;
       }
    }
    return false;
}

std::pair<int, int> sumOfBlock() 
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < block; i++) 
    {
        if (useForSum(i))
        {
            sum += i;
            count++;
        }
    }
    return std::pair<int, int> (sum, count);
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();
    
    std::pair<int, int> basicBlockSum = sumOfBlock();
    long long runningSum = 0;
    int latestBlock = 0;
    // sum known blocks
    for (int i = 0; i + block < limitNumber; i+= block) 
    {
        runningSum += basicBlockSum.first;
        runningSum += basicBlockSum.second * i; 
        latestBlock = i + block;
    }
    // handle leftOver
    for (int i = latestBlock; i < limitNumber; i++) 
    {
        if (useForSum(i))                   
        {
            runningSum += i;
        }
    } 

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << runningSum << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
