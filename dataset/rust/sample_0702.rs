fn update_grid(grid: &Vec<Vec<i32>>, size: usize) -> Vec<Vec<i32>> {
    let mut new_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for x in 0.max(i as isize - 1)..(size as isize).min(i as isize + 2) {
                for y in 0.max(j as isize - 1)..(size as isize).min(j as isize + 2) {
                    if (x, y) != (i as isize, j as isize) {
                        neighbors += grid[x as usize][y as usize];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 { 1 } else if neighbors == 2 { grid[i][j] } else { 0 };
        }
    }
    new_grid
}

fn simulate(size: usize, steps: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![if i % 2 == 0 { 1 } else { 0 }; size]; size];
    for _ in 0..steps {
        grid = update_grid(&grid, size);
    }
    grid
}

fn main() {
    let size = 5;
    let steps = 10;
    let result = simulate(size, steps);
    for row in result {
        println!("{}", row.iter().map(|&x| x.to_string()).collect::<Vec<String>>().join(" "));
    }
}