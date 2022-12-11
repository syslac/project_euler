#include <chrono>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <array>

static const int start = 1;
static const int end = 1000;
static const std::array<int, 20> letterCounts = { 
    0, // zero, will not be counted in hundreds or tens
    3, // "one"
    3, // "two"
    5, // "three"
    4, // "four"
    4, // "five"
    3, // "six"
    5, // "seven" 
    5, // "eight"
    4, // "nine"
    3, // "ten"
    6, // "eleven" 
    6, // "twelve"
    8, // "thirteen"
    8, // "fourteen"
    7, // "fifteen"
    7, // "sixteen"
    9, // "seventeen"
    8, // "eighteen"
    8  // "nineteen"
};
static const std::array<int, 10> tensLetterCounts = { 
    0, 0, // zeroes and tens will not be part of written number
    6, // "twenty"
    6, // "thirty"
    5, // "forty"
    5, // "fifty"
    5, // "sixty"
    7, // "seventy"
    6, // "eighty"
    6, // "ninety"
};
static const int hundredBoost = 10; // counts "hundred and"
static const int thousandBoost = 11; // counts "one thousand"

int getLetters (int n) 
{
    if (n == 1000) 
    {
        return thousandBoost;
    }
    int res = 0;

    int hundreds = int(n / 100);
    int other = n % 100;

    if (hundreds >= 1) 
    {
        res += letterCounts.at(hundreds) + hundredBoost;
    }
    if (other < 20) 
    {
        if (other == 0 && hundreds >= 1) 
        {
            res -= 3; // need to remove "and"
        }
        res += letterCounts.at(other);
        return res;
    }
    else 
    {
        int tens = int (other / 10);
        int digit = other % 10;
        res += tensLetterCounts.at(tens);
        res += letterCounts.at(digit);
        return res;
    }
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    int runningSum = 0;
    for (int i = start; i <= end; i++) 
    {
        std::cout << i << ":" << getLetters(i) << std::endl;
        runningSum += getLetters(i);
    }
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << runningSum << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
