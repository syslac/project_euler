#include <chrono>
#include <iostream>

const int N = 20;

int main() 
{
    auto startTm = std::chrono::high_resolution_clock::now();

    long numProduct = 1;
    long denProduct = 1;
    for (long i = 1; i <= N; i++) 
    {
        if ((N+i) % 2 == 0) 
        {
            numProduct *= 2;
        }
        else 
        {
            numProduct *= (N+i);
        }
        if (i > N/2) 
        {
            denProduct *= 1;
        }
        else 
        {
            denProduct *= i;
        }
    }
    long result = numProduct / denProduct;
    
    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << result << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
