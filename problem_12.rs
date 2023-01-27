use std::time::{Instant};

const LIMIT_NUMBER: usize = 1000000;
const TARGET_FACTORS: usize = 500;

fn triangular(n: usize) -> usize
{
    (n * (n + 1)) / 2
}

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

fn factorize(n : usize, primes: &Vec<usize>) -> Vec<usize> 
{
    let mut exponents: Vec<usize> = vec![0usize; primes.len()];
    for i in 0..primes.len()
    {
        if primes[i] > f64::sqrt(n as f64) as usize 
        {
            break;
        }
        let mut cur: usize = primes[i];
        let mut cur_exponent: usize = 0;
        while n % cur == 0 && cur <= n 
        {
            cur_exponent = cur_exponent + 1;
            cur = cur * primes[i];
        }
        exponents[i] = cur_exponent;
    }
    return exponents;
}


fn main () 
{
    let start = Instant::now();

    let primes: Vec<usize> = all_primes_using_sieve(LIMIT_NUMBER);
    for i in 0..LIMIT_NUMBER
    {
        let candidate: usize = triangular(i);
        let exponents = factorize(candidate, &primes);
        let mut number_of_factors: usize = 1;
        for j in 0..primes.len()
        {  
            if primes[j] > f64::sqrt(candidate as f64) as usize
            {
                break;
            }
            number_of_factors = number_of_factors * (exponents[j] + 1);
        }
        if number_of_factors >= TARGET_FACTORS
        {
            println!("Result: {}", candidate);
            break;
        }
    }
    
    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}


