### Problem [https://projecteuler.net/problem=16](https://projecteuler.net/problem=16)

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

### Solution

Modular arithmetics should be key here, e.g. 2^5 mod 10 = 2.
We have 1000 = 2 (500) * 2 (250) * 2 (125) * 5 (25) * 5 (5) * 5 = 2^3 * 5^3
So 2^1000 = 2 ^ (2^3 * 5^3) = 256 ^ 125

But also 1000 = 512 + 256 + 128 + 64 + 32 + 8
And 2^512 = 2^(2^9), so it's the 9th step of a procedure always squaring the result.
So, I "only" need to perform 10 multiplications to have all the numbers needed here, which are the 3rd, 5th, 6th, 7th, 8th, 9th step in this procedure.
Then one more multiplication of all of them to get the final result.

Now, to get all of the digits of this number, unfortunately turns out modular arithmetics cannot handle it, with any precision, so I have to implement a class for arbitrary length integers (as string); luckily, the only operation I need here is multiplication.