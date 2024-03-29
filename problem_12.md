### Problem [https://projecteuler.net/problem=12](https://projecteuler.net/problem=12)

The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

### Solution

First of all, the triangular numbers have a known closed form, which can be proved by induction: T(n) = (n (n + 1))/2, proof follows.
Supposing T(n - 1) = ((n - 1) n) / 2, we have T(n) = (by definition) = T(n - 1) + n = (n^2 - n) / 2 + n = (n^2 - n + 2n) / 2 = (n^2 + n) / 2 = (n ( n + 1 ))/2, qed.

This way, I can skip the cycle for the generation of triangular numbers and have a single multiplication.

Second, the number of divisors can be computed base on the prime factorization; if my number n is a product of p_1 .. p_n, each to the power q_1 .. q_n, then I expect the number of divisors to be (q_1 + 1) * ... * (q_n + 1), as each choice of the exponent, independent on the others, will give a different divisor. The +1 appears because 0 is a valid choice of exponent meaning that prime will not appear in the divisor factorization.

Let's try it with for example the next number in the example sequence: 36 = 2^2 * 3^2. So I expect 9 divisors, which are, indeed, 1, 2, 3, 4, 6, 9, 12, 18, 36.

So the problem reduces to the usual computing a big enough list of primes (how big will be big enough? I'm not sure, will try 1000000 maybe), then rolling out triangular numbers and factorizing them.
