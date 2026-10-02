extern crate ndarray;
use ndarray::{Array2, arr2};

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let rows = grid.shape()[0];
    let cols = grid.shape()[1];
    let mut new_grid = Array2::<i32>::zeros((rows, cols));
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![max(0, i - 1)..min(rows, i + 2), max(0, j - 1)..min(cols, j + 2)])
                               .sum();
            if grid[[i, j]] == 1 && (neighbors == 3 || neighbors == 4) {
                new_grid[[i, j]] = 1;
            } else if grid[[i, j]] == 0 && neighbors == 3 {
                new_grid[[i, j]] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let grid_size = 50;
    let mut grid = Array2::<i32>::random((grid_size, grid_size), rand::distributions::Uniform::new(0, 2));
    loop {
        grid = update_grid(&grid);
    }
}