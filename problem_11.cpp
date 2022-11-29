#include <chrono>
#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

const std::string inputMatrix = "\
0802229738150040007504050778521250779108\
4949994017811857608717409843694804566200\
8149317355791429937140675388300349133665\
5270952304601142692468560132567137023691\
2231167151676389419236542240402866331380\
2447326099034502447533537836842035171250\
3298812864236710263840675954706618386470\
6726206802621220956394396308409166499421\
2455580566739926971778789683148834896372\
2136230975007644204535140061339734313395\
7817532822753167159403800462161409535692\
1639054296353147555888240017542436298557\
8656004835718907054444374460215851541758\
1980816805944769287392138652177704895540\
0452088397359916079757321626267933279866\
8836688757622072034633674655123263935369\
0442167338253911249472180846293240627636\
2069364172302388346299698267598574043616\
2073352978319001743149714886811623570554\
0170547183515469169233486143520189196748";
const int searchLen = 4;
const int numDigits = 2;
const int matrixRank = 20;
enum SearchDirection 
{
    Horizontal,
    Vertical,
    DiagonalFw,
    DiagonalBw
};
std::map<SearchDirection, int> searchIncrement = {
    {SearchDirection::Horizontal, numDigits}, 
    {SearchDirection::Vertical, matrixRank * numDigits},
    {SearchDirection::DiagonalFw, (matrixRank + 1) * numDigits},
    {SearchDirection::DiagonalBw, (matrixRank - 1) * numDigits}
};

std::pair<std::array<int, searchLen>, bool> getSubstringAsNumbers (int startX, int startY, SearchDirection dir)
{
    std::array<int, searchLen> toRet;
    const char* startingPointer = inputMatrix.c_str() 
        + startX * searchIncrement[SearchDirection::Horizontal] 
        + startY * searchIncrement[SearchDirection::Vertical];

    for (int i = 0; i < searchLen; i++, startingPointer += searchIncrement[dir])
    {
        char curNumber[numDigits]; 
        memcpy(curNumber, startingPointer, numDigits * sizeof(char));
        int number = atoi(curNumber); 
        if (number < 20) 
        {
            return std::pair<std::array<int, searchLen>, bool> (toRet, true);
        }
        toRet.at(i) = number;
    }
    return std::pair<std::array<int, searchLen>, bool> (toRet, false);
}

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long biggestProduct = 0;
    std::array<int, searchLen> biggestNumbers;
    for (int y = 0; y < matrixRank; y++) 
    {
        for (int x = 0; x < matrixRank; x++)
        {
            for (SearchDirection i = SearchDirection::Horizontal; i <= SearchDirection::DiagonalBw; i = SearchDirection(int(i) + 1)) 
            {
                if (i == SearchDirection::Horizontal && x > matrixRank - searchLen) 
                {
                    continue;
                }
                if (i == SearchDirection::Vertical && y > matrixRank - searchLen) 
                {
                    continue;
                }
                if (i == SearchDirection::DiagonalFw && (y > matrixRank - searchLen || x > matrixRank - searchLen)) 
                {
                    continue;
                }
                if (i == SearchDirection::DiagonalBw && (y > matrixRank - searchLen || x < searchLen - 1)) 
                {
                    continue;
                }
                auto subString = getSubstringAsNumbers(x, y, i);
                if (subString.second) 
                {
                    continue;
                }
                long runningProduct = 1;
                for (int j = 0; j < subString.first.size(); j++)
                {
                    runningProduct *= subString.first.at(j);
                }
                if (runningProduct > biggestProduct)
                {
                    biggestProduct = runningProduct;
                    biggestNumbers = subString.first;
                }
            }
        }
    }

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Digits: "; 
    for (int i = 0; i < searchLen; i++) 
    {
        std::cout << biggestNumbers.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Solution: " << biggestProduct << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
