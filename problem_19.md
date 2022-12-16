### Problem [https://projecteuler.net/problem=19](https://projecteuler.net/problem=19)

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

### Solution

There's probably some clever modular arithmetics I could do here, but seriously, it's probably easier to just code up a date class; summing one week at a time is only ~50*100 iterations, so not completely crazy.

Tedious, not difficult.