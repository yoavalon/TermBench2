extern crate rand;

use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = grid.clone();
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid[i][(j + cols - 1) % cols] + grid[i][(j + 1) % cols] + grid[(i + rows - 1) % rows][j] + grid[(i + 1) % rows][j] + grid[(i + rows - 1) % rows][(j + cols - 1) % cols] + grid[(i + rows - 1) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j + cols - 1) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[i][j] = 0;
                }
            } else if neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    *grid = new_grid;
}

fn main() {
    let grid_size = 10;
    let mut grid: Vec<Vec<i32>> = vec![vec![0; grid_size]; grid_size];
    let mut rng = rand::thread_rng();
    for row in grid.iter_mut() {
        for cell in row.iter_mut() {
            *cell = rng.gen_range(0..2);
        }
    }
    loop {
        update_grid(&mut grid);
        for row in &grid {
            println!("{:?}", row);
        }
        println!("{}", "-".repeat(20));
    }
}