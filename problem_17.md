### Problem [https://projecteuler.net/problem=17](https://projecteuler.net/problem=17)

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

### Solution

Seems just a question of correctly laying out the input data to have the tightest possible inner cycle; for sure I need all the letter-counts of numbers 1-19, plus a separate one for the tens, and just a const boost for the hundreds, I think.
Plus, correct handling of all the zeroes should be automatic, but better check.