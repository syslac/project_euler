use std::time::{Instant};

const LIMIT_NUMBER: usize = 120000;
const SOUGHT_PRIME: usize = 10001;

fn all_primes_using_sieve (n: usize) -> Vec<usize>
{
    let mut sieve: Vec<u8> = vec![];
    let mut primes: Vec<usize> = vec![];
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
    for i in 2..n 
    {
        if sieve[i] == 0
        {
            primes.push(i);
        }
    }
    return primes;
}

fn main () 
{
    let start = Instant::now();

    let all_primes = all_primes_using_sieve(LIMIT_NUMBER);
    if all_primes.len() >= SOUGHT_PRIME
    {
        println!("Result: {}", all_primes[SOUGHT_PRIME  - 1]);
    }

    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}

