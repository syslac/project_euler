### Problem [https://projecteuler.net/problem=4](https://projecteuler.net/problem=4)

The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is


Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

### Solution

It's known that (a1 + .. + an)^2 = a1^2 + .. + an^2... plus 2 times all the mixed products.
These mixed products are therefore the difference we're looking for, and we can use the usual nested cycles with y >= x (triangular argument).
