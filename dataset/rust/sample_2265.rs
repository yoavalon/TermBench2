extern crate ndarray;

use ndarray::{Array2, arr2};

fn update_grid(grid: &Array2<i32>, size: usize) -> Array2<i32> {
    let mut new_grid = Array2::zeros((size, size));
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let neighbors = grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]).iter().sum::<i32>() - grid[[i, j]];
            if grid[[i, j]] == 0 && neighbors > 2 {
                new_grid[[i, j]] = 1;
            } else if grid[[i, j]] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[[i, j]] = 0;
            } else {
                new_grid[[i, j]] = grid[[i, j]];
            }
        }
    }
    new_grid
}

fn main() {
    let size = 50;
    let mut grid = Array2::zeros((size, size));
    grid[[size / 2, size / 2]] = 1;
    loop {
        grid = update_grid(&grid, size);
    }
}