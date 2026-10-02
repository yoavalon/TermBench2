extern crate rand;

use rand::Rng;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut grid = vec![vec![0; size]; size];
    let mut rng = rand::thread_rng();
    for row in grid.iter_mut() {
        for cell in row.iter_mut() {
            *cell = rng.gen_range(0..2);
        }
    }
    grid
}

fn evolve(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut next_grid = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let mut neighbors = 0;
            for x in i.saturating_sub(1)..=std::cmp::min(i + 1, size - 1) {
                for y in j.saturating_sub(1)..=std::cmp::min(j + 1, size - 1) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                next_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                next_grid[i][j] = 1;
            } else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }
    next_grid
}

fn main() {
    let grid_size = 100;
    let mut grid = initialize_grid(grid_size);
    loop {
        grid = evolve(&grid);
    }
}