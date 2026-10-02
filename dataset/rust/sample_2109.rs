extern crate rand;

use rand::Rng;

fn simulate() {
    let mut grid = [[0.0; 100]; 100];
    let mut rng = rand::thread_rng();

    for i in 0..100 {
        for j in 0..100 {
            grid[i][j] = rng.gen_range(0.0..1.0);
        }
    }

    loop {
        let mut new_grid = [[0.0; 100]; 100];
        for i in 1..99 {
            for j in 1..99 {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate();
}