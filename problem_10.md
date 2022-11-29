### Problem [https://projecteuler.net/problem=10](https://projecteuler.net/problem=10)

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

### Solution

I don't know if there is any clever induction-based formula for sum of primes; I don't think so, as I feel that would require knowing something strong about prime distribution, so this will be a bruteforce-like solution, via the usual sieve.

Will use a reduce pattern for the inline sum just for variation.
