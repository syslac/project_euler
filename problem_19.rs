use std::time::{Instant};

const DAYS_OF_WEEK: u8 = 7;
const MONTHS_OF_YEAR: usize = 12;
const MONTHS: [u8; MONTHS_OF_YEAR] = [
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
];

struct Date 
{
    day: u8,
    month: u8,
    year: u16,
    dow: u8,
}

impl Date
{
    fn init (d: u8, m: u8, y: u16, w : Option<u8>) -> Date
    {
        return Date { day: d, month: m, year: y, dow: w.unwrap_or(0) };
    }

    fn is_leap_year(&self) -> bool
    {
        return 
            self.year % 4 == 0
            && (self.year % 100 != 0 
            || self.year % 400 == 0);
    }

    fn get_month_len(&self) -> u8
    {
        if !self.is_leap_year() || self.month != 2 
        {
            return MONTHS[(self.month - 1) as usize];
        }
        else 
        {
            return MONTHS[(self.month - 1) as usize] + 1;
        }
    }

    fn sum_interval(&mut self, days: u8)
    {
        self.dow += days % DAYS_OF_WEEK;
        if self.day + days <= self.get_month_len() 
        {
            self.day = self.day + days;
            return;
        }
        else 
        {
            self.day = ((self.day + days) % (self.get_month_len() + 1)) + 1;
            self.month += 1;
            if self.month > (MONTHS_OF_YEAR) as u8
            {
                self.month = 1;
                self.year += 1;
            }
        }
    }

    fn is_less_than(&self, d: &Date) -> bool
    {
        if self.year < d.year 
        {
            return true;
        }
        else if self.year > d.year 
        {
            return false;
        }
        if self.month < d.month 
        {
            return true;
        }
        else if self.month > d.month 
        {
            return false;
        }
        if self.day < d.day 
        {
            return true;
        }
        return false;
    }
}


fn main () 
{
    let start_tm = Instant::now();

    let mut start: Date = Date::init(1, 1, 1900, Some(1));
    let start_count: Date = Date::init(31, 12, 1900, None);
    let end_count: Date = Date::init(1, 1, 2001, None);

    let mut started_count: bool = false;
    let mut counted_sundays: u16 = 0;
    start.sum_interval(6); // move to first Sunday
    while start.is_less_than(&end_count) 
    {
        if started_count || start_count.is_less_than(&start)
        {
            started_count = true;
            if start.day == 1 
            {
                counted_sundays = counted_sundays + 1;
            }
        }
        start.sum_interval(7); // move weekly
    }

    println!("Result: {}", counted_sundays);
    let duration = start_tm.elapsed();
    println!("Timing: {}", duration.as_nanos());
}







