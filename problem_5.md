### Problem [https://projecteuler.net/problem=4](https://projecteuler.net/problem=4)

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


### Solution

I think this will be more theory than programming; first step is that, if a number is evenly divisible by x, and x = y * z, then it is also evenly divisible by y and z.
This means, starting from 20, the largest, only count a subset, as follows:

20 gives us also 10, 5, 4, 2.
19
18 gives us also 9, 6, 3.
17
16 gives us also 8.
15
14 gives us also 7.
13
12
11

And so, the problem reduces to finding the mcm of the numbers from 11 to 20.
This is 11 * 13 * 17 * 19 * 2^4 * 3^2 * 5 * 7
