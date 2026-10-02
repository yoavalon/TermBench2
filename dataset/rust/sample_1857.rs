fn decay_reward(reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    for _ in 0..steps {
        rewards.push(reward);
        reward *= decay_rate;
    }
    rewards
}

fn main() {
    decay_reward(1.0, 0.9, 10);
}