use std::time::{Instant};

const MAX_STARTER: usize = 1000000;

fn next_collatz (i: usize) -> usize
{
    return match i % 2
    {
        0 => i / 2,
        1 => 3 * i + 1,
        _ => 1,
    }
}

fn main () 
{
    let start = Instant::now();

    let mut acc_collatz: [bool; MAX_STARTER] = [false; MAX_STARTER];
    let mut longest_sequence: usize = 0;
    let mut longest_sequence_num: usize = 0;
    let mut filled_acc_collatz: usize = 1;

    for i in 1..MAX_STARTER
    {
        if acc_collatz[i]
        {
            continue;
        }
        acc_collatz[i] = true;
        filled_acc_collatz = filled_acc_collatz + 1;
        let mut cur: usize = i;
        let mut cur_sequence: usize = 0;
        while cur != 1
        {
            cur = next_collatz(cur);
            cur_sequence = cur_sequence + 1;
            if cur > 1 && cur < MAX_STARTER && !acc_collatz[i]
            {
                acc_collatz[i] = true;
                filled_acc_collatz = filled_acc_collatz + 1;
            }
        }
        if filled_acc_collatz >= MAX_STARTER
        {
            break;
        }
        if cur_sequence > longest_sequence
        {
            longest_sequence = cur_sequence;
            longest_sequence_num = i; 
        }
    }

    println!("Result: {}", longest_sequence_num);
    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}



