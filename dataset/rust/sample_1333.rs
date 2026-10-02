extern crate ndarray;
use ndarray::prelude::*;

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let mut new_grid = grid.to_owned();
    let rows = grid.shape()[0];
    let cols = grid.shape()[1];
    for i in 1..rows - 1 {
        for j in 1..cols - 1 {
            let neighbors = grid.slice(s![i - 1..i + 2, j - 1..j + 2]).sum() - grid[[i, j]];
            if grid[[i, j]] != 0 && (neighbors < 2 || neighbors > 3) {
                new_grid[[i, j]] = 0;
            } else if grid[[i, j]] == 0 && neighbors == 3 {
                new_grid[[i, j]] = 1;
            }
        }
    }
    new_grid
}

fn simulate(grid: &Array2<i32>, steps: usize) -> Array2<i32> {
    let mut current_grid = grid.to_owned();
    for _ in 0..steps {
        current_grid = update_grid(&current_grid);
    }
    current_grid
}

fn main() {
    let size = 50;
    let mut grid = Array2::<i32>::zeros((size, size));
    grid.slice_mut(s![20..25, 20..25]).assign(&Array2::<i32>::from_shape_fn((5, 5), |_| rand::random::<i32>() % 2));
    let final_grid = simulate(&grid, 100);
    println!("{:?}", final_grid);
}