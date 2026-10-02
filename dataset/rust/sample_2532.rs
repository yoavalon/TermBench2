extern crate rand;

use rand::Rng;

fn decay_reward(reward: f64, decay_rate: f64) -> f64 {
    reward * decay_rate
}

fn simulate_reward_decay(initial_reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current_reward = initial_reward;
    for _ in 0..steps {
        rewards.push(current_reward);
        current_reward = decay_reward(current_reward, decay_rate);
    }
    rewards
}

fn main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
    for (step, reward) in rewards.iter().enumerate() {
        println!("Step {}: Reward {:.2}", step + 1, reward);
    }
}