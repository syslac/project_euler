#include <chrono>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <array>

const int maxExp = 305;
const int base = 2;
const int numFactors = 6;
const int maxDoublings = 10;
const int digitMaxVal = 10;
std::array<int, numFactors> usedSteps = { 3, 5, 6, 7, 8, 9 };

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

std::vector<unsigned char> compute_result () 
{
    std::vector<std::vector<unsigned char>> res;
    std::vector<unsigned char> workingNum = { (unsigned char) base };
    for (int i = 1; i < maxDoublings; i++) 
    {
        workingNum = multiply_strings(workingNum, workingNum);
        for (int j = 0; j < numFactors; j++)
        {
            if (i == usedSteps.at(j))
            {
                res.push_back(workingNum);
                break;
            }
        }
    }
    std::vector<unsigned char> acc = { (unsigned char) 1 };
    for (int i = 0; i < (int) res.size(); i++)
    {
        acc = multiply_strings(acc, res.at(i));
    }
    return acc;
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    int runningSum = 0;
    std::vector<unsigned char> res = compute_result();
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
