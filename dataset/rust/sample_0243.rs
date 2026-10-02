extern crate ndarray;

use ndarray::{Array2, arr2};

struct Automata {
    grid: Array2<i32>,
    boundary_type: String,
    size: usize,
}

impl Automata {
    fn new(size: usize, boundary_type: &str) -> Automata {
        Automata {
            grid: Array2::zeros((size, size)),
            boundary_type: boundary_type.to_string(),
            size,
        }
    }

    fn apply_boundary_conditions(&mut self) {
        if self.boundary_type == "fixed" {
            self.grid.column_mut(0).fill(1);
            self.grid.column_mut(self.size - 1).fill(1);
            self.grid.row_mut(0).fill(1);
            self.grid.row_mut(self.size - 1).fill(1);
        } else if self.boundary_type == "periodic" {
            self.grid.column_mut(0).assign(&self.grid.column(self.size - 2));
            self.grid.column_mut(self.size - 1).assign(&self.grid.column(1));
            self.grid.row_mut(0).assign(&self.grid.row(self.size - 2));
            self.grid.row_mut(self.size - 1).assign(&self.grid.row(1));
        }
    }

    fn update_grid(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 1..self.size - 1 {
            for j in 1..self.size - 1 {
                let neighbors = self.grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]).sum() - self.grid[[i, j]];
                if self.grid[[i, j]] == 1 {
                    if neighbors < 2 || neighbors > 3 {
                        new_grid[[i, j]] = 0;
                    }
                } else if neighbors == 3 {
                    new_grid[[i, j]] = 1;
                }
            }
        }
        self.grid = new_grid;
    }
}

struct Simulation {
    automata: Automata,
    steps: usize,
}

impl Simulation {
    fn new(automata: Automata, steps: usize) -> Simulation {
        Simulation {
            automata,
            steps,
        }
    }

    fn run(&mut self) {
        for _ in 0..self.steps {
            self.automata.apply_boundary_conditions();
            self.automata.update_grid();
        }
    }
}

fn main() {
    let size = 10;
    let boundary_type = "fixed";
    let steps = 50;
    let automata = Automata::new(size, boundary_type);
    let mut simulation = Simulation::new(automata, steps);
    simulation.run();
}