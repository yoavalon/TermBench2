fn decay_reward(reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut decayed_rewards = Vec::new();
    for step in 0..steps {
        decayed_rewards.push(reward * decay_rate.powi(step as i32));
    }
    decayed_rewards
}

fn calculate_final_reward(initial_reward: f64, decay_rate: f64, steps: usize) -> f64 {
    let rewards = decay_reward(initial_reward, decay_rate, steps);
    rewards.iter().sum()
}

fn main() {
    let initial = 100.0;
    let rate = 0.9;
    let steps = 10;
    let final_reward = calculate_final_reward(initial, rate, steps);
    println!("{}", final_reward);
}