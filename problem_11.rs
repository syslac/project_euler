use std::time::{Instant};

const INPUT_MATRIX : &str = "\
0802229738150040007504050778521250779108\
4949994017811857608717409843694804566200\
8149317355791429937140675388300349133665\
5270952304601142692468560132567137023691\
2231167151676389419236542240402866331380\
2447326099034502447533537836842035171250\
3298812864236710263840675954706618386470\
6726206802621220956394396308409166499421\
2455580566739926971778789683148834896372\
2136230975007644204535140061339734313395\
7817532822753167159403800462161409535692\
1639054296353147555888240017542436298557\
8656004835718907054444374460215851541758\
1980816805944769287392138652177704895540\
0452088397359916079757321626267933279866\
8836688757622072034633674655123263935369\
0442167338253911249472180846293240627636\
2069364172302388346299698267598574043616\
2073352978319001743149714886811623570554\
0170547183515469169233486143520189196748";
const SEARCH_LEN: usize = 4;
const NUM_DIGITS: usize = 2;
const MATRIX_RANK: usize = 20;
const SEARCH_MODES: usize = 4;

#[derive(Copy, Clone)]
enum SearchDirection
{
    Horizontal,
    Vertical,
    DiagonalFw,
    DiagonalBw,
}
const DIRECTION_ITERATOR: [SearchDirection; SEARCH_MODES] = [
    SearchDirection::Horizontal,
    SearchDirection::Vertical, 
    SearchDirection::DiagonalBw,
    SearchDirection::DiagonalFw
];

fn search_increment(dir: SearchDirection) -> usize
{
    match dir 
    {
        SearchDirection::Horizontal => NUM_DIGITS,
        SearchDirection::Vertical => MATRIX_RANK * NUM_DIGITS,
        SearchDirection::DiagonalFw => (MATRIX_RANK + 1) * NUM_DIGITS,
        SearchDirection::DiagonalBw => (MATRIX_RANK - 1) * NUM_DIGITS,
    }
}

fn is_in_limits(dir: SearchDirection, x: usize, y: usize) -> bool
{
    match dir 
    {
        SearchDirection::Horizontal => x <= MATRIX_RANK - SEARCH_LEN,
        SearchDirection::Vertical => y <= MATRIX_RANK - SEARCH_LEN,
        SearchDirection::DiagonalFw => y <= MATRIX_RANK - SEARCH_LEN && x <= MATRIX_RANK - SEARCH_LEN,
        SearchDirection::DiagonalBw => y <= MATRIX_RANK - SEARCH_LEN && x >= SEARCH_LEN - 1,
    }
}

fn get_substring_as_numbers (start_x : usize, start_y : usize, dir : SearchDirection) -> ([u8; SEARCH_LEN], bool)
{
    let starting_point: usize = start_x * search_increment(SearchDirection::Horizontal) + start_y * search_increment(SearchDirection::Vertical);
    let mut to_ret : [u8; SEARCH_LEN] = [0; SEARCH_LEN];
    let inc = search_increment(dir);

    for i in 0..SEARCH_LEN
    {
        to_ret[i] = INPUT_MATRIX[starting_point + (i * inc)..starting_point + (i * inc + NUM_DIGITS)].parse::<u8>().unwrap();
        if to_ret[i] < 20
        {
            return (to_ret, true);
        }
    }
    return (to_ret, false);
}


fn main () 
{
    let start = Instant::now();

    let mut biggest_product : usize = 0;
    for y in 0..MATRIX_RANK
    {
        for x in 0..MATRIX_RANK
        {
            for i in DIRECTION_ITERATOR
            {
                if !is_in_limits(i, x, y)
                {
                    continue;
                }
                let sub_string = get_substring_as_numbers(x, y, i);
                if sub_string.1 
                {
                    continue;
                }
                let running_product : usize = (sub_string.0).iter().fold(1, |acc, x| (acc * (*x as usize)).into() );
                biggest_product = biggest_product.max(running_product);
            }
        }
    }

    let duration = start.elapsed();
    println!("Result: {}", biggest_product);
    println!("Timing: {}", duration.as_nanos());
}

