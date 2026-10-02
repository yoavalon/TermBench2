extern crate ndarray;
use ndarray::Array1;

fn calculate_reward_decay(initial_reward: f64, decay_rate: f64, time_steps: usize) -> Array1<f64> {
    let mut rewards = Array1::zeros(time_steps);
    rewards[0] = initial_reward;
    for t in 1..time_steps {
        rewards[t] = rewards[t - 1] * (1.0 - decay_rate);
    }
    rewards
}

fn simulate_terminal_condition(rewards: &Array1<f64>, threshold: f64) -> bool {
    for &reward in rewards {
        if reward < threshold {
            return true;
        }
    }
    false
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.05;
    let time_steps = 20;
    let threshold = 0.01;
    let rewards = calculate_reward_decay(initial_reward, decay_rate, time_steps);
    let terminal_condition = simulate_terminal_condition(&rewards, threshold);
    println!("Terminal Condition Met: {}", terminal_condition);
}