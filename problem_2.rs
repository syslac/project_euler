use std::time::{Instant};

const LIMIT_NUMBER: usize = 4000000;
const CACHE_PRESIZE: usize = 100;

struct Fibonacci 
{
    fib_cache : Vec<usize>,
}

impl Fibonacci 
{
    fn init () -> Fibonacci 
    {
        let mut ret = Fibonacci { fib_cache: vec![] };
        ret.fib_cache.resize(CACHE_PRESIZE, 0);
        ret
    }

    fn clean_cache (&mut self) 
    {
        self.fib_cache.resize(0, 0);
    }

    fn fib (&mut self, n : usize) -> usize 
    {
        if n <= 1
        {
            self.fib_cache[n] = 1;
            return 1;
        }
        if self.fib_cache[n] != 0 { return self.fib_cache[n] };
        let prev2 = if self.fib_cache[n - 2] != 0 { self.fib_cache[n - 2] } else { self.fib(n - 2) };
        let prev1 = if self.fib_cache[n - 1] != 0 { self.fib_cache[n - 1] } else { self.fib(n - 1) };
        self.fib_cache[n] = prev2 + prev1;
        return prev2 + prev1;
    }
}

fn main () 
{
    let start = Instant::now();

    let mut fib_with_cache = Fibonacci::init();
    let mut final_sum = 0;
    let mut cur_fib = 0;
    let mut i = 1;
    while cur_fib < LIMIT_NUMBER 
    {
        cur_fib = fib_with_cache.fib(i);
        if cur_fib % 2 == 0
        {
            final_sum += cur_fib;
        }
        i = i + 1;
    }
    fib_with_cache.clean_cache();

    let duration = start.elapsed();
    println!("Result: {}", final_sum);
    println!("Timing: {}", duration.as_nanos());
}