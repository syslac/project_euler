use std::time::{Instant};

const BASE: u8 = 2;
const NUM_FACTORS: usize = 6;
const MAX_DOUBLINGS: usize = 10;
const DIGIT_MAX_VAL: u8 = 10u8;
const USED_STEPS: [usize; NUM_FACTORS] = [ 3, 5, 6, 7, 8, 9 ];

fn multiply_strings (f1 : &Vec<u8>, f2: &Vec<u8>) -> Vec<u8>
{
    let mut res: Vec<u8> = vec![];
    res.resize(f1.len() + f2.len() + 1, 0);
    for i in 0..f1.len()
    {
        for j in 0..f2.len()
        {
            let res_pos: usize = i + j;
            let digit_mult: u8 = f1[i] * f2[j];
            res[res_pos] = res[res_pos] + ((digit_mult) % DIGIT_MAX_VAL);
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

fn compute_result () -> Vec<u8>
{
    let mut res: Vec<Vec<u8>> = vec![];
    let mut working_num: Vec<u8> = vec![ BASE ];
    for i in 1..MAX_DOUBLINGS
    {
        working_num = multiply_strings(&working_num, &working_num);
        for j in 0..NUM_FACTORS
        {
            if i == USED_STEPS[j]
            {
                res.push(working_num.clone());
                break;
            }
        }
    }
    return res.iter().fold(vec![ 1u8 ], |acc, x| multiply_strings(&acc, x))
}

fn main () 
{
    let start = Instant::now();

    let res: Vec<u8> = compute_result();
    let running_sum: usize = res.iter().fold(0, |acc, x| acc + (*x as usize));
    
    println!("Result: {}", running_sum);
    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}




