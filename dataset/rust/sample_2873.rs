use ndarray::prelude::*;

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let (rows, cols) = grid.dim();
    let mut new_grid = Array2::zeros((rows, cols));
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![i - 1..i + 2, j - 1..j + 2]).sum() - grid[[i, j]];
            new_grid[[i, j]] = if neighbors == 3 || (neighbors == 2 && grid[[i, j]] == 1) { 1 } else { 0 };
        }
    }
    new_grid
}

fn main() {
    let mut grid = Array2::zeros((50, 50));
    grid[[25, 25]] = 1;
    loop {
        grid = update_grid(&grid);
    }
}