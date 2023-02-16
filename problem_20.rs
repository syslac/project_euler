use std::time::{Instant};

const DIGIT_MAX_VAL: u8 = 10;

fn multiply_strings (f1: &Vec<u8>, f2: &Vec<u8>) -> Vec<u8>
{
    let mut res: Vec<u8> = vec![];
    res.resize(f1.len() + f2.len() + 1, 0);
    for i in 0..f1.len()
    {
        for j in 0..f2.len()
        {
            let res_pos: usize = i + j;
            let digit_mult: u8 = f1[i] * f2[j];
            res[res_pos] = res[res_pos] + (digit_mult) % DIGIT_MAX_VAL;
            if digit_mult >= DIGIT_MAX_VAL 
            {
                res[res_pos + 1] = res[res_pos + 1] + (digit_mult / DIGIT_MAX_VAL);
            }
            for k in res_pos..res.len()
            {
                let rip: u8 = res[k] / DIGIT_MAX_VAL;
                if rip >= 1 
                {
                    res[k] = res[k] - rip * DIGIT_MAX_VAL;
                    res[k + 1] = res[k + 1] + rip;
                }
                else 
                {
                    break;
                }
            }
        }
    }
    while res.len() > 0 && res[res.len() - 1] == 0 
    {
        res.resize(res.len() - 1, 0);
    }
    return res;
}

fn decrement_string (n: &Vec<u8>) -> Vec<u8>
{
    let mut res = n.clone();
    for i in 0..res.len()
    {
        // I don't need to iterate more than this; decrement and if needed truncate the length
        if res[i] > 0 
        {
            res[i] = res[i] - 1;
            if res[i] == 0 && i > 0 && i == res.len() - 1 
            {
                res.resize(res.len() - 1, 0);
            }
            return res;
        }
        else 
        {
            res[i] = DIGIT_MAX_VAL - 1;
        }
    }
    return res;
}

fn factorial_strings (n: Vec<u8>) -> Vec<u8>
{
    if n.len() == 1 && n[0] <= 1 
    {
        return n;
    }
    return multiply_strings(&n, &factorial_strings(decrement_string(&n)));
}


fn main () 
{
    let start_tm = Instant::now();

    let target_num: Vec<u8> = vec![0, 0, 1];
    let res: Vec<u8> = factorial_strings(target_num);
    let running_sum: usize = res.iter().fold(0, |acc, x| acc + (*x as usize));

    println!("Result: {}", running_sum);
    let duration = start_tm.elapsed();
    println!("Timing: {}", duration.as_nanos());
}
