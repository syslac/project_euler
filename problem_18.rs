use std::time::{Instant};

const NUM_LINES: usize = 15;

fn init_data() -> [Vec<usize>; NUM_LINES]
{
    let mut triangle: [Vec<usize>; NUM_LINES] = Default::default();
    triangle[0] = vec![ 75 ];
    triangle[1] = vec![ 95, 64 ];
    triangle[2] = vec![ 17, 47, 82 ];
    triangle[3] = vec![ 18, 35, 87, 10 ];
    triangle[4] = vec![ 20, 04, 82, 47, 65 ];
    triangle[5] = vec![ 19, 01, 23, 75, 03, 34 ];
    triangle[6] = vec![ 88, 02, 77, 73, 07, 63, 67 ];
    triangle[7] = vec![ 99, 65, 04, 28, 06, 16, 70, 92 ];
    triangle[8] = vec![ 41, 41, 26, 56, 83, 40, 80, 70, 33 ];
    triangle[9] = vec![ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 ];
    triangle[10] = vec![ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 ];
    triangle[11] = vec![ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 ];
    triangle[12] = vec![ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 ];
    triangle[13] = vec![ 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 ];
    triangle[14] = vec![  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 ];
    return triangle;
}

#[derive(Clone, Copy)]
struct Point 
{
    row: usize,
    col: usize,
}

impl Point 
{
    fn init(r: usize, c: usize) -> Point 
    { 
        return Point { row: r, col: c };
    }
}

#[derive(Clone)]
struct Path 
{
    total: usize,
    path: Vec<Point>,
}

impl Path 
{
    fn init() -> Path
    { 
        return Path { total: 0, path: vec![] }; 
    }

    fn append (&mut self, new_pt: Point, triangle: &[Vec<usize>; NUM_LINES]) 
    {
        if 
            new_pt.row < NUM_LINES
            && new_pt.col < triangle[new_pt.row].len()
        {
            self.total = self.total + triangle[new_pt.row][new_pt.col];
            self.path.push(new_pt);
        }
    }

    fn get_total (&self) -> usize { return self.total; }
    //fn get_element (&self, i: usize) -> Point { return self.path[i]; }
    //fn get_len (&self) -> usize { return self.path.len(); }
}


fn init_paths (triangle: &[Vec<usize>; NUM_LINES]) -> [Vec<Path>; NUM_LINES]
{
    let mut paths: [Vec<Path>; NUM_LINES] = Default::default();
    for row in 0..NUM_LINES
    {
        paths[row].resize(triangle[row].len(), Path::init());
    }
    return paths;
}

fn compute_paths(paths: &mut [Vec<Path>; NUM_LINES], triangle: &[Vec<usize>; NUM_LINES]) 
{
    for row in (0..NUM_LINES).rev()
    {
        for col in 0..triangle[row].len()
        {
            if row == NUM_LINES - 1 
            {
                paths[row][col].append(Point::init(row, col), &triangle);
            }
            else 
            {
                if paths[row + 1][col].get_total() > 
                paths[row + 1][col + 1].get_total()
                {
                    paths[row][col] = paths[row + 1][col].clone();

                }
                else 
                {
                    paths[row][col] = paths[row + 1][col + 1].clone();
                }
                paths[row][col].append(Point::init(row, col), &triangle);
            }
        }
    }
}

fn main () 
{
    let start = Instant::now();

    let triangle: [Vec<usize>; NUM_LINES] = init_data();

    let mut triangle_paths: [Vec<Path>; NUM_LINES] = init_paths(&triangle);
    compute_paths(&mut triangle_paths, &triangle);
    

    println!("Result: {}", triangle_paths[0][0].get_total());
    let duration = start.elapsed();
    println!("Timing: {}", duration.as_nanos());
}






