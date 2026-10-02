extern crate rand;

use rand::Rng;

fn boundary_conditions() {
    let mut rng = rand::thread_rng();
    let mut state = rng.gen::<f64>();
    let gamma = 0.99;
    let mut rewards = Vec::new();

    for _ in 0..1000 {
        if state < 0.1 {
            break;
        }
        let reward = state * rng.gen::<f64>();
        rewards.push(reward);
        state *= gamma;
    }
}

fn main() {
    boundary_conditions();
}