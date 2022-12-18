### Problem [https://projecteuler.net/problem=20](https://projecteuler.net/problem=20)

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

### Solution

This is a different version of problem 16: 100 multiplications is not even that bad, but I will need a library to handle multiplications of integers with arbitrary length; this was already implemented in 16, so will be reused.