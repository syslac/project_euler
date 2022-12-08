### Problem [https://projecteuler.net/problem=15](https://projecteuler.net/problem=15)

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?


### Solution

Routes of this kind through an NxN grid require exactly 2N steps; and also, exactly N of them must be right (R) and N must be down (D); so, the solution could be the permutations of the string RRR...RRRDDD...DDD, except that most of the permutations are equivalent (e.g. I can permute the first N Rs as much as I like, the end result will be the same.

Another way of looking at it is that I have 2N choices, where at any step I may choose R or D, except that once I reach N Rs or N Ds my next choices are forced.

Both the permutations (2N!) and the choice-based approach (2^N) would be easy to compute, but I don't know how to codify the equivalence classes in one case, and the constraints in the other, and my combinatorics knowledge is not so fresh anymore to get to a closed formula here.

Let's see if induction gets me anywhere:
N = 1 -> 2 paths
N = 2 -> 6 paths
N = 3 -> 12 (continued from N = 2, by RD and DR) + 8 (for each of the previous path, every time they touch a point of the form (x, 2) or (2, x), I can make it continue through the outer border and then uniquely to the end corner).
N = 4 -> 40 (same as before) + ???

Based on some combinatorics searching online, what I require may be permutations with repetition, where the formula, in my case, would be (2N)! / ((N!)*(N!)), which simplifies to (product(i=N+1...2N))/N!.

Then of course I need some ways to avoid computing the full factorials, since the numbers are too big anyway.
