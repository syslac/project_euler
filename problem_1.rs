use std::time::{Duration, Instant};

const LIMIT_NUMBER: usize = 1000;
const BLOCK_SIZE: usize = 30;

fn use_for_sum (n : usize) -> bool 
{
    return match n 
    {
        i if i % 3 == 0 => true,
        i if i % 5 == 0 => true,
        _ => false
    }
}

fn sum_of_block () -> (usize, usize)
{
    return (0usize..BLOCK_SIZE)
        .filter(|x| use_for_sum(*x))
        .map(|x| (x, 1usize))
        .fold((0usize, 0usize), |acc, x| (acc.0 + x.0, acc.1 + x.1))
}

fn main () 
{
    let start = Instant::now();
    let basic_block_sum = sum_of_block();
    let mut running_sum = 0;
    let mut latest_block = 0;
    for i in (0usize..(LIMIT_NUMBER - BLOCK_SIZE)).step_by(BLOCK_SIZE)
    {
        running_sum += basic_block_sum.0;
        running_sum += basic_block_sum.1 * i;
        latest_block = i + BLOCK_SIZE
    }
    let final_sum = (latest_block..LIMIT_NUMBER)
        .filter(|x| use_for_sum(*x))
        .fold(running_sum, |acc, x| (acc + x));

    let duration = start.elapsed();
    println!("Result: {}", final_sum);
    println!("Timing: {}", duration.as_nanos());
}