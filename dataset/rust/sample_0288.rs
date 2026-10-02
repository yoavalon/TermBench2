extern crate rand;

use rand::Rng;
use std::f64;

struct StateSimulator {
    conditions: Vec<f64>,
    boundaries: (f64, f64),
    iteration: usize,
}

impl StateSimulator {
    fn new(initial_conditions: Vec<f64>, boundary_conditions: (f64, f64)) -> Self {
        StateSimulator {
            conditions: initial_conditions,
            boundaries: boundary_conditions,
            iteration: 0,
        }
    }

    fn update_conditions(&mut self) {
        let mut rng = rand::thread_rng();
        for cond in self.conditions.iter_mut() {
            *cond += rng.gen::<f64>() * 0.1;
            *cond = f64::clamp(*cond, self.boundaries.0, self.boundaries.1);
        }
    }

    fn check_stability(&self) -> bool {
        for &cond in &self.conditions {
            if (cond - self.boundaries.0).abs() < 0.01 || (cond - self.boundaries.1).abs() < 0.01 {
                return true;
            }
        }
        false
    }
}

struct BoundaryConditions {
    limit1: f64,
    limit2: f64,
}

impl BoundaryConditions {
    fn new(lower: f64, upper: f64) -> Self {
        BoundaryConditions {
            limit1: lower,
            limit2: upper,
        }
    }

    fn get_boundaries(&self) -> (f64, f64) {
        (self.limit1, self.limit2)
    }
}

fn simulate_state(initial: Vec<f64>, boundaries: (f64, f64), max_iterations: usize) -> Vec<f64> {
    let mut simulator = StateSimulator::new(initial, boundaries);
    for _ in 0..max_iterations {
        simulator.update_conditions();
        if simulator.check_stability() {
            break;
        }
    }
    simulator.conditions
}

fn main() {
    let initial_conditions = vec![0.5, 0.5, 0.5];
    let boundary_conditions = BoundaryConditions::new(0.0, 1.0);
    let max_iterations = 100;
    let final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries(), max_iterations);
    println!("{:?}", final_state);
}