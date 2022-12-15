### Problem [https://projecteuler.net/problem=18](https://projecteuler.net/problem=18)

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

### Solution

Trying to go into it unspoiled, seems a good method should be on some level inductive, or divide-and-conquer.

What seems like it could work, but I'm not sure if it will be efficient enough, is constructing the paths from the bottom:
on the bottom row, every number has a trivial path which is just itself.

Inductively, for every number on the row above the path is itself, joined to whichever of the paths on bottom left or bottom right gives the best result. This is even easier if I want to track just the totals, but I may want to track the full path if I ever want to "plot" it out.
And this is linear in number of nodes in the triangle, which means quadratic in the rows, instead of exponential, which doesn't seem too bad.

Note: "go left" translates as (i, j) -> (i+1, j) while "go right" translates as (i+1, j+1)