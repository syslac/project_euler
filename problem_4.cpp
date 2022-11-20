#include <chrono>
#include <iostream>
#include <functional>

bool hasThreeDigitDivisor (long n) 
{
    for (int i = 999; i >= 100; i--) 
    {
        if (n % i == 0 && n / i >= 100 && n / i < 1000)
        {
            std::cout << "Divisors: " << i << "&" << (n / i) << std::endl;
            return true;
        }
    }
    return false;
}

const int max_digit = 9;
int digits[3] = { max_digit, max_digit, max_digit };

std::function<long()> generateNextPalindrome = [&digits] () 
{
    long toRet = long(digits[0]) * long(1e5 + 1) + long(digits[1]) * long(1e4 + 10) + long(digits[2]) * long(1e3 + 1e2);
    if (digits[2] > 0)
    {
        (digits[2])--;
    }
    else if (digits[1] > 0) 
    {
        (digits[2]) = max_digit;
        (digits[1])--;
    }
    else if (digits[0] > 0) 
    {
        (digits[1]) = max_digit;
        (digits[0])--;
    }
    else
    {
        return (long)0;
    }
    return toRet;
};

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long palindromeToTest = 1e6;
    do {
        palindromeToTest = generateNextPalindrome();
        if (hasThreeDigitDivisor(palindromeToTest))
        {
            break;
        }
    }
    while (palindromeToTest != 0);

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << palindromeToTest << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
