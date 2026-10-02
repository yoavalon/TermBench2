extern crate ndarray;

use ndarray::Array1;

fn compute_reward_decay(reward: f64, decay_rate: f64, steps: usize) -> f64 {
    reward * decay_rate.powi(steps as i32)
}

fn simulate_sequence(initial_reward: f64, decay_rate: f64, max_steps: usize) -> Array1<f64> {
    let mut sequence = Array1::zeros(max_steps);
    let mut current_reward = initial_reward;
    for step in 0..max_steps {
        current_reward = compute_reward_decay(current_reward, decay_rate, 1);
        sequence[step] = current_reward;
    }
    sequence
}

fn main() {
    let initial_value = 100.0;
    let decay_factor = 0.95;
    let total_iterations = 10;
    let result = simulate_sequence(initial_value, decay_factor, total_iterations);
    println!("{:?}", result);
}