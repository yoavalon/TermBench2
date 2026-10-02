extern crate ndarray;

use ndarray::{Array2, arr2};

fn initialize_grid(size: usize) -> Array2<i32> {
    let mut grid = Array2::zeros((size, size));
    grid[[size / 2, size / 2]] = 1;
    grid
}

fn apply_boundary_conditions(grid: &mut Array2<i32>) {
    let size = grid.shape()[0];
    for i in 0..size {
        grid[[0, i]] = 0;
        grid[[size - 1, i]] = 0;
        grid[[i, 0]] = 0;
        grid[[i, size - 1]] = 0;
    }
}

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let mut new_grid = grid.to_owned();
    let size = grid.shape()[0];
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let neighbors = grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]).sum() - grid[[i, j]];
            if grid[[i, j]] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    new_grid[[i, j]] = 0;
                }
            } else if neighbors == 3 {
                new_grid[[i, j]] = 1;
            }
        }
    }
    new_grid
}

fn simulate(steps: usize) -> Array2<i32> {
    let size = 50;
    let mut grid = initialize_grid(size);
    apply_boundary_conditions(&mut grid);
    for _ in 0..steps {
        grid = update_grid(&grid);
        apply_boundary_conditions(&mut grid);
    }
    grid
}

fn main() {
    let steps = 100;
    let result = simulate(steps);
    println!("{:?}", result);
}