#include <chrono>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <array>

std::vector<unsigned char> targetNum = {0, 0, 1};
const unsigned char digitMaxVal = 10;

std::vector<unsigned char> multiply_strings (std::vector<unsigned char> f1, std::vector<unsigned char> f2) 
{
    std::vector<unsigned char> res;
    res.resize(f1.size() + f2.size() + 1);
    memset(res.data(), 0, res.size() * sizeof(unsigned char));
    for (int i = 0; i < f1.size(); i++) 
    {
        for (int j = 0; j < f2.size(); j++) 
        {
            int resPos = i + j;
            int digitMult = f1.at(i) * f2.at(j);
            res.at(resPos) += (digitMult) % digitMaxVal;
            if (digitMult >= digitMaxVal) 
            {
                res.at(resPos + 1) += int(digitMult / digitMaxVal);
            }
            for (int k = resPos; k < res.size(); k++) 
            {
                int rip = int(res.at(k) / digitMaxVal);
                if (rip >= 1) 
                {
                    res.at(k) -= rip * digitMaxVal;
                    res.at(k + 1) += rip;
                }
                else 
                {
                    break;
                }
            }
        }
    }
    while (res.size() > 0 && res.at(res.size() - 1) == 0) 
    {
        res.resize(res.size() - 1);
    }
    return res;
}

std::vector<unsigned char> decrement_string (std::vector<unsigned char> n)
{
    for (int i = 0; i < n.size(); i++)
    {
        // I don't need to iterate more than this; decrement and if needed truncate the length
        if (n.at(i) > 0) 
        {
            n.at(i) -= 1;
            if (n.at(i) == 0 && i > 0 && i == n.size() - 1) 
            {
                n.resize(n.size() - 1);
            }
            return n;
        }
        else 
        {
            n.at(i) = 9;
        }
    }
    return n;
}

std::vector<unsigned char> factorial_strings (std::vector<unsigned char> n) 
{
    if (n.size() == 1 && n.at(0) <= 1) 
    {
        return n;
    }
    return multiply_strings(n, factorial_strings(decrement_string(n)));
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    int runningSum = 0;
    std::vector<unsigned char> res = factorial_strings(targetNum);
    for (int i = 0; i < res.size(); i++) 
    {
        runningSum += (int) res.at(i);
        std::cout << int(res.at(res.size() - 1 - i));
    }
    std::cout << std::endl;
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << runningSum << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
