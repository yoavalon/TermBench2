use std::vec::Vec;

fn reward_decay(initial_value: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = vec![initial_value];
    for _ in 0..steps {
        let last_reward = rewards.last().unwrap();
        rewards.push(last_reward * decay_rate);
    }
    rewards
}

fn simulate_reward_decay() {
    let value = 1.0;
    let rate = 0.9;
    let mut step = 0;
    loop {
        let rewards = reward_decay(value, rate, step);
        println!("{:?}", rewards);
        step += 1;
    }
}

fn main() {
    simulate_reward_decay();
}