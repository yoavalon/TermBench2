extern crate ndarray;
extern crate rand;

use ndarray::{Array2, arr2};
use rand::Rng;

struct Automaton {
    grid: Array2<u8>,
    rules: std::collections::HashMap<u8, u8>,
}

impl Automaton {
    fn new(size: usize, rules: std::collections::HashMap<u8, u8>) -> Self {
        let mut rng = rand::thread_rng();
        let grid = Array2::from_shape_fn((size, size), |_| rng.gen_range(0..2));
        Automaton { grid, rules }
    }

    fn apply_rules(&mut self) {
        let mut new_grid = self.grid.clone();
        for i in 1..self.grid.nrows() - 1 {
            for j in 1..self.grid.ncols() - 1 {
                let neighbors = self.grid.slice(s![i - 1..=i + 1, j - 1..=j + 1]);
                let total: u8 = neighbors.iter().sum();
                if let Some(&value) = self.rules.get(&total) {
                    new_grid[[i, j]] = value;
                }
            }
        }
        self.grid = new_grid;
    }

    fn update(&mut self) {
        self.apply_rules();
    }
}

struct Simulation {
    automaton: Automaton,
    steps: usize,
}

impl Simulation {
    fn new(size: usize, rules: std::collections::HashMap<u8, u8>, steps: usize) -> Self {
        let automaton = Automaton::new(size, rules);
        Simulation { automaton, steps }
    }

    fn run(&mut self) {
        for _ in 0..self.steps {
            self.automaton.update();
        }
    }
}

fn main() {
    let size = 10;
    let mut rules = std::collections::HashMap::new();
    rules.insert(3, 1);
    rules.insert(12, 1);
    let steps = 50;
    let mut simulation = Simulation::new(size, rules, steps);
    simulation.run();
}