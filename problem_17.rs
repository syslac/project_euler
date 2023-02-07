use std::time::{Instant};

const START: usize = 1;
const END: usize = 1000;
const LETTER_COUNTS: [usize; 20] = [ 
    0, // zero, will not be counted in hundreds or tens
    3, // "one"
    3, // "two"
    5, // "three"
    4, // "four"
    4, // "five"
    3, // "six"
    5, // "seven" 
    5, // "eight"
    4, // "nine"
    3, // "ten"
    6, // "eleven" 
    6, // "twelve"
    8, // "thirteen"
    8, // "fourteen"
    7, // "fifteen"
    7, // "sixteen"
    9, // "seventeen"
    8, // "eighteen"
    8  // "nineteen"
];
const TENS_LETTERS_COUNTS: [usize; 10] = [ 
    0, 0, // zeroes and tens will not be part of written number
    6, // "twenty"
    6, // "thirty"
    5, // "forty"
    5, // "fifty"
    5, // "sixty"
    7, // "seventy"
    6, // "eighty"
    6, // "ninety"
];
const HUNDRED_BOOST: usize = 10; // counts "hundred and"
const THOUSAND_BOOST: usize = 11; // counts "one thousand"

fn get_letters (n: usize) -> usize
{
    if n == 1000
    {
        return THOUSAND_BOOST;
    }
    let mut res: usize = 0;

    let hundreds: usize = n / 100;
    let other: usize = n % 100;
    if hundreds >= 1 
    {
        res = res + LETTER_COUNTS[hundreds] + HUNDRED_BOOST;
    }
    if other < 20
    {
        if other == 0 && hundreds >= 1 
        {
            res = res - 3; // need to remove "and"
        }
        res = res + LETTER_COUNTS[other];
        return res;
    }
    else 
    {
        let tens: usize = other / 10;
        let digit: usize = other % 10;
        res = res + TENS_LETTERS_COUNTS[tens];
        res = res + LETTER_COUNTS[digit];
        return res;
    }
}


fn main () 
{
    let start = Instant::now();

    let running_sum = (START..END + 1).fold(0, |acc, x| acc + get_letters(x));
    
    println!("Result: {}", running_sum);
    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}





