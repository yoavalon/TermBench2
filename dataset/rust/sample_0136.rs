extern crate ndarray;
use ndarray::prelude::*;

fn initialize_grid(size: usize) -> Array2<i32> {
    Array2::zeros((size, size))
}

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let mut new_grid = grid.to_owned();
    let (rows, cols) = grid.dim();
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![max(0, i - 1)..min(rows, i + 2), max(0, j - 1)..min(cols, j + 2)]).sum::<i32>() - grid[[i, j]];
            if grid[[i, j]] == 0 && neighbors == 3 {
                new_grid[[i, j]] = 1;
            } else if grid[[i, j]] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[[i, j]] = 0;
            }
        }
    }
    new_grid
}

fn main() {
    let grid_size = 50;
    let iterations = 100;
    let mut grid = initialize_grid(grid_size);
    for _ in 0..iterations {
        grid = update_grid(&grid);
    }
    println!("{}", grid);
}