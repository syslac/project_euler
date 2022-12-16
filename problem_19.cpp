#include <chrono>
#include <iostream>
#include <cmath>
#include <cstring>
#include <array>

static const int days_of_week = 7;
static const int months_of_year = 12;
static const std::array<int, months_of_year> months = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};

struct Date 
{
    int day;
    int month;
    int year;
    int dow;

    Date(int d, int m, int y, int w) 
    {
        day = d;
        month = m;
        year = y;
        dow = w;
    }

    Date(int d, int m, int y) 
    {
        day = d;
        month = m;
        year = y;
    }

    bool isLeapYear() 
    {
        return 
            year % 4 == 0
            && (year % 100 != 0 
            || year % 400 == 0);
    }

    int getMonthLen() 
    {
        if (!isLeapYear() || month != 2) 
        {
            return months.at(month - 1);
        }
        else 
        {
            return months.at(month - 1) + 1;
        }
    }

    void sumInterval(int days)
    {
        dow += days % days_of_week;
        if (day + days <= getMonthLen()) 
        {
            day += days;
            return;
        }
        else 
        {
            day = ((day + days) % (getMonthLen() + 1)) + 1;
            month += 1;
            if (month > months_of_year) 
            {
                month = 1;
                year += 1;
            }
        }
    }

    bool isLessThan(Date d)
    {
        if (year < d.year) 
        {
            return true;
        }
        else if (year > d.year) 
        {
            return false;
        }
        if (month < d.month) 
        {
            return true;
        }
        else if (month > d.month) 
        {
            return false;
        }
        if (day < d.day) 
        {
            return true;
        }
        return false;
    }
};

int main() 
{
    Date start(1, 1, 1900, 1);
    Date startCount(31, 12, 1900);
    Date endCount(1, 1, 2001);
    auto startTm = std::chrono::high_resolution_clock::now();

    bool startedCount = false;
    int countedSundays = 0;
    start.sumInterval(6); // move to first Sunday
    while (start.isLessThan(endCount)) 
    {
        if (startedCount || startCount.isLessThan(start))
        {
            startedCount = true;
            if (start.day == 1) 
            {
                countedSundays++;
            }
        }
        start.sumInterval(7); // move weekly
    }

    auto endTm = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTm-startTm);
    std::cout << "Solution: " << countedSundays << std::endl;
    std::cout << "Timing: " << microseconds.count() << "ns\n";
}
