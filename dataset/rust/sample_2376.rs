extern crate ndarray;
use ndarray::{Array2, arr2};

struct CellularAutomata {
    grid: Array2<f32>,
    rule: i32,
}

impl CellularAutomata {
    fn new(size: usize, rule: i32) -> Self {
        let mut grid = Array2::<f32>::zeros((size, size));
        grid[size / 2, size / 2] = 1.0;
        CellularAutomata { grid, rule }
    }

    fn apply_rule(&self, neighborhood: &Array2<f32>) -> f32 {
        let s = neighborhood.sum();
        if s == 3.0 {
            1.0
        } else if s == 2.0 {
            neighborhood[neighborhood.shape()[0] / 2, neighborhood.shape()[1] / 2]
        } else {
            0.0
        }
    }

    fn update_grid(&mut self) {
        let mut new_grid = Array2::<f32>::zeros(self.grid.dim());
        for i in 1..self.grid.shape()[0] - 1 {
            for j in 1..self.grid.shape()[1] - 1 {
                let neighborhood = self.grid.slice(s![i - 1..i + 2, j - 1..j + 2]);
                new_grid[[i, j]] = self.apply_rule(&neighborhood);
            }
        }
        self.grid = new_grid;
    }
}

struct FluidSimulation {
    ca: CellularAutomata,
}

impl FluidSimulation {
    fn new(size: usize, rule: i32) -> Self {
        FluidSimulation { ca: CellularAutomata::new(size, rule) }
    }

    fn simulate(&mut self) {
        loop {
            self.ca.update_grid();
        }
    }
}

fn main() {
    let mut sim = FluidSimulation::new(50, 30);
    sim.simulate();
}