extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2};

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let rows = grid.nrows();
    let cols = grid.ncols();
    let mut new_grid = grid.clone();
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]);
            let alive_neighbors = neighbors.sum() - grid[[i, j]];
            if grid[[i, j]] == 1 && (alive_neighbors < 2 || alive_neighbors > 3) {
                new_grid[[i, j]] = 0;
            } else if grid[[i, j]] == 0 && alive_neighbors == 3 {
                new_grid[[i, j]] = 1;
            }
        }
    }
    new_grid
}

fn simulate(grid_size: usize) {
    let mut rng = rand::thread_rng();
    let mut grid: Array2<i32> = Array2::from_shape_vec((grid_size, grid_size), (0..grid_size * grid_size).map(|_| rng.gen::<i32>() % 2).collect()).unwrap();
    loop {
        grid = update_grid(&grid);
        println!("{}", grid);
    }
}

fn main() {
    simulate(10);
}