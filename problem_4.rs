use std::time::{Instant};

const MAX_DIGIT:usize = 9;

fn has_three_digit_divisor (n: usize) -> bool
{
    for i in (100..1000).rev()
    {
        if n % i == 0 && n / i >= 100 && n / i < 1000 
        {
            println!("Divisors: {} | {}", i, n/i);
            return true
        }
    }
    false
}


fn main () 
{
    let mut digits: (usize, usize, usize) = (MAX_DIGIT, MAX_DIGIT, MAX_DIGIT);
    let mut generate_next_palindrome = || -> usize 
    {
        let to_ret : usize = digits.0 * (100000 + 1) + digits.1 * (10000 + 10) + digits.2 * (1000 + 100);
        if digits.2 > 0
        {
            digits.2 = digits.2 - 1;
        }
        else if digits.1 > 0
        {
            digits.2 = MAX_DIGIT;
            digits.1 = digits.1 - 1;
        }
        else if digits.0 > 0
        {
            digits.1 = MAX_DIGIT;
            digits.0 = digits.0 - 1;
        }
        else 
        {
            return 0
        }
        return to_ret
    };

    let start = Instant::now();

    let mut palindrome = generate_next_palindrome();
    while palindrome > 0 && !has_three_digit_divisor(palindrome)
    {
        palindrome = generate_next_palindrome();
    }
    let duration = start.elapsed();
    println!("Result: {}", palindrome);
    println!("Timing: {}", duration.as_nanos());
}

