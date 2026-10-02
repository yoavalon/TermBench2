extern crate rand;

use rand::Rng;
use std::iter;

fn update_grid(grid: &mut Vec<Vec<i32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0; cols]; rows];
    for i in 0..rows {
        for j in 0..cols {
            let neighbors = iter::once(i - 1)
                .chain(iter::once(i))
                .chain(iter::once(i + 1))
                .flat_map(|i| iter::once(j - 1).chain(iter::once(j)).chain(iter::once(j + 1)))
                .filter(|&(i, j)| i >= 0 && i < rows as isize && j >= 0 && j < cols as isize)
                .filter(|&(i, j)| grid[i as usize][j as usize] == 1)
                .count() as i32;
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    *grid = new_grid;
}

fn simulate() -> impl Iterator<Item = Vec<Vec<i32>>> {
    let grid_size = 50;
    let mut grid = (0..grid_size)
        .map(|_| (0..grid_size).map(|_| if rand::thread_rng().gen_bool(0.5) { 1 } else { 0 }).collect())
        .collect();
    iter::repeat_with(move || {
        update_grid(&mut grid);
        grid.clone()
    })
}

fn main() {
    let mut sim = simulate();
    for _ in 0..1000 {
        println!("{:?}", sim.next().unwrap());
    }
}