### Problem [https://projecteuler.net/problem=3](https://projecteuler.net/problem=3)

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

### Solution

Simplest way that comes to mind is finding all the primes up to the square root of the given number, then going through them in descending order testing if they divide the original number, even though this still feels a little too much like brute force.
Implementation will follow standard Erathostenes' sieve.
