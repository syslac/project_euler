use std::time::{Instant};

const WANTED_SUM : usize = 1000;
const LOWER_BOUND : usize = 250;

fn main () 
{
    let start = Instant::now();

    let triplet: (usize, usize, usize);
    for b in LOWER_BOUND..WANTED_SUM
    {
        let a : f64 = 1000.0 * (1000.0 - 2.0 * (b as f64))/(2000.0 - 2.0 * b as f64);
        if a.floor() == a
        {
            let c : f64 = (WANTED_SUM as f64) - a - (b as f64);
            triplet = (a as usize, b, c as usize);
            println!("Result: {}", triplet.0 * triplet.1 * triplet.2);
            break;
        }

    }

    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}



