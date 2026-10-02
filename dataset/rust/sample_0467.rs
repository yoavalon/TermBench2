fn initialize_grid(size: usize) -> Vec<Vec<usize>> {
    vec![vec![0; size]; size]
}

fn update_grid(grid: &Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let mut new_grid = grid.clone();
    for i in 0..grid.len() {
        for j in 0..grid[i].len() {
            let mut neighbors = 0;
            for x in -1..=1 {
                for y in -1..=1 {
                    if x == 0 && y == 0 {
                        continue;
                    }
                    let ni = i as isize + x;
                    let nj = j as isize + y;
                    if ni >= 0 && ni < grid.len() as isize && nj >= 0 && nj < grid[i].len() as isize {
                        neighbors += grid[ni as usize][nj as usize];
                    }
                }
            }
            new_grid[i][j] = if neighbors == 3 { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let grid_size = 10;
    let mut grid = initialize_grid(grid_size);
    loop {
        grid = update_grid(&grid);
    }
}