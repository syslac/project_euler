#include <chrono>
#include <iostream>
#include <cmath>

const int wantedSum = 1000;
const int lowerBound = 250;

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    int triplet[3];
    for (int b = lowerBound; b < wantedSum; b++)
    {
        float a = 1000.0f * (1000.0f - 2.0f * float(b))/(2000.0f - 2.0f * float(b));
        std::cout << a << std::endl;
        if (std::floor(a) == a)
        {
            float c = sqrt(a*a + float(b)*float(b));
            if (std::floor(c) == c)
            {
                triplet[0] = (int)a;
                triplet[1] = b;
                triplet[2] = (int)c;
                break;
            }
        }
    }
    long product = triplet[0] * triplet[1] * triplet[2];

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Triplet: "; 
    for (int i = 0; i < 3; i++) 
    {
        std::cout << triplet[i] << ",";
    }
    std::cout << std::endl;
    std::cout << "Solution: " << product << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
