extern crate num_traits;

use num_traits::Pow;

fn decay_reward(reward: f64, decay_rate: f64, steps: u32) -> f64 {
    reward * decay_rate.pow(steps)
}

fn calculate_total_reward(initial_reward: f64, decay_rate: f64, max_steps: u32) -> f64 {
    let mut total_reward = 0.0;
    for step in 0..max_steps {
        total_reward += decay_reward(initial_reward, decay_rate, step);
    }
    total_reward
}

fn main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let max_steps = 1000;
    let total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps);
    println!("{}", total_reward);
}