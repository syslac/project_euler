### Problem [https://projecteuler.net/problem=7](https://projecteuler.net/problem=7)

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

### Solution

I want to replicate the sieve from problem #3 here, but in order to get the sqrt(n) optimization, I need to know what's a sensible n where I can stop. 

In order to get a first estimate, I'll use the known asymptotic approximation: number of primes less or equal than n behaves like n / log(n) asymptotically. So, we want n / log(n) = 10001, n ~= 120 000 maybe.
