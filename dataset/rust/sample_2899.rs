extern crate ndarray;
use ndarray::{Array2, arr2};

fn update_grid(grid: &Array2<i32>) -> Array2<i32> {
    let rows = grid.nrows();
    let cols = grid.ncols();
    let mut new_grid = grid.clone();
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = grid.slice(s![i-1..=i+1, j-1..=j+1]).sum() - grid[[i, j]];
            if grid[[i, j]] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[[i, j]] = 0;
            } else if grid[[i, j]] == 0 && neighbors == 3 {
                new_grid[[i, j]] = 1;
            }
        }
    }
    new_grid
}

fn simulate() {
    let grid = Array2::<i32>::random((10, 10), ndarray_rand::rand_distr::Uniform::new(0, 2));
    loop {
        let grid = update_grid(&grid);
        println!("{:?}", grid);
        if grid.iter().all(|&x| x == 0) {
            break;
        }
    }
}

fn main() {
    simulate();
}