extern crate rand;

use rand::prelude::*;
use std::vec::Vec;

struct AutomataGrid {
    grid: Vec<Vec<i32>>,
    size: usize,
}

impl AutomataGrid {
    fn new(size: usize, density: f64) -> Self {
        let mut grid = vec![vec![0; size]; size];
        let mut rng = thread_rng();
        for i in 0..size {
            for j in 0..size {
                grid[i][j] = if rng.gen::<f64>() < density { 1 } else { 0 };
            }
        }
        AutomataGrid { grid, size }
    }

    fn apply_rules(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 1..self.size - 1 {
            for j in 1..self.size - 1 {
                let neighbors = self.grid[i - 1][j - 1]
                    + self.grid[i - 1][j]
                    + self.grid[i - 1][j + 1]
                    + self.grid[i][j - 1]
                    + self.grid[i][j + 1]
                    + self.grid[i + 1][j - 1]
                    + self.grid[i + 1][j]
                    + self.grid[i + 1][j + 1];
                if self.grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else if self.grid[i][j] == 0 && neighbors == 3 {
                    new_grid[i][j] = 1;
                }
            }
        }
        self.grid = new_grid;
    }

    fn set_boundary_conditions(&mut self) {
        for i in 0..self.size {
            self.grid[i][0] = self.grid[i][self.size - 2];
            self.grid[i][self.size - 1] = self.grid[i][1];
            self.grid[0][i] = self.grid[self.size - 2][i];
            self.grid[self.size - 1][i] = self.grid[1][i];
        }
    }
}

struct Simulation {
    grid: AutomataGrid,
    steps: usize,
}

impl Simulation {
    fn new(grid: AutomataGrid, steps: usize) -> Self {
        Simulation { grid, steps }
    }

    fn run(&mut self) {
        for _ in 0..self.steps {
            self.grid.apply_rules();
            self.grid.set_boundary_conditions();
        }
    }
}

fn main() {
    let size = 10;
    let density = 0.3;
    let steps = 50;
    let grid = AutomataGrid::new(size, density);
    let mut simulation = Simulation::new(grid, steps);
    simulation.run();
}