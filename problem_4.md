### Problem [https://projecteuler.net/problem=4](https://projecteuler.net/problem=4)

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

### Solution

Best solution seems to be enumerating palindromes in descending order, which is also algorithmically easier to do than enumerating products in descending order (the ordering part is not trivial, I think), then checking for factors above 100. 
Not sure about performance, but we will see.
