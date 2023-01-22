use std::time::{Instant};

const LIMIT_NUMBER: usize = 2000000;

fn reduce_primes_using_sieve<F> (n: usize, f: F, mut acc: usize) -> usize
    where F: Fn(usize, usize) -> usize
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
    for i in 2..n 
    {
        if sieve[i] == 0
        {
            acc = f(acc, i);
        }
    }
    return acc;
}

fn main () 
{
    let start = Instant::now();

    let result = reduce_primes_using_sieve(LIMIT_NUMBER, |acc, x| acc + x, 0);
    println!("Result: {}", result);

    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}


