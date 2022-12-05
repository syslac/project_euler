### Problem [https://projecteuler.net/problem=14](https://projecteuler.net/problem=14)

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

### Solution

One thing we can be sure, to start, is that, given 0 < n < 1000000, then two numbers that have a longer sequence are, surely, 2 * n (which we can't consider here if above 1000000) and (n - 1)/3 (if integer).
This means of course we can't follow the sequence backwards, because it branches; consider e.g. you could get to 10 both from 3 and from 20.

The sequence of course ends when we get to an even power of 2, so ideally we want that 3n + 1 stays away from an even power of 2. What relationship is there between the factorization of an (odd) n and that of 3n+1? I can't figure any out:
3 -> 10 = 2 * 5
5 -> 16 = 2^4
7 -> 22 = 2 * 11
9 -> 28 = 2^2 * 7
11 -> 35 = 2 * 17
13 -> 40 = 2^3 * 5

Maybe as a first solution, a semi-brute force approach wouldn't be too bad, with an accumulator, like in the sieve, where I cross out any number I already passed in a previous iteration.
