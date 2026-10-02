fn reward_decay(initial_reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current_reward = initial_reward;
    for _ in 0..steps {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    rewards
}

fn main() {
    reward_decay(1.0, 0.95, 10);
}