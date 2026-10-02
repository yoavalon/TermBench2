extern crate ndarray;
use ndarray::prelude::*;
use rand::Rng;

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let rows = grid.nrows();
    let cols = grid.ncols();
    let mut new_grid = Array2::<i32>::zeros((rows, cols));
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![i-1..i+2, j-1..j+2])
                              .sum() - grid[[i, j]];
            if grid[[i, j]] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[[i, j]] = 0;
            } else if grid[[i, j]] == 0 && neighbors == 3 {
                new_grid[[i, j]] = 1;
            } else {
                new_grid[[i, j]] = grid[[i, j]];
            }
        }
    }
    new_grid
}

fn main() {
    let size = 10;
    let mut rng = rand::thread_rng();
    let mut grid = Array2::<i32>::from_shape_fn((size, size), |_| rng.gen_range(0..2));
    loop {
        grid = update_grid(&grid);
    }
}