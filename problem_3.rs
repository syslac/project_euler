use std::time::{Instant};

const LIMIT_NUMBER: usize = 600851475143;

fn max_prime_using_sieve<F> (n: usize, f: F) -> usize
    where F: Fn(usize) -> bool
{
    let mut sieve: Vec<u8> = vec![];
    sieve.resize(n + 1, 0);
    let limit = f64::sqrt(n as f64) as usize;
    for i in 2..limit 
    {
        if sieve[i] == 0 
        {
            for j in ((i + i)..n).step_by(i)
            {
                sieve[j] = 1;
            }
        }
    }
    for i in (2..n).rev() 
    {
        if sieve[i] == 0
        {
            if f(i) { return i; }
        }
    }
    return 1;
}

fn main () 
{
    let start = Instant::now();

    let divides_limit = |x| if LIMIT_NUMBER % x == 0 { true } else { false };
    let prime = max_prime_using_sieve(f64::sqrt(LIMIT_NUMBER as f64) as usize, divides_limit);

    let duration = start.elapsed();
    println!("Result: {}", prime);
    println!("Timing: {}", duration.as_nanos());
}
