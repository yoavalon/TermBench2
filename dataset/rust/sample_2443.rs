fn reward_decay(epochs: usize, decay_rate: f64) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current_reward = 1.0;
    for _ in 0..epochs {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    rewards
}

fn main() {
    println!("{:?}", reward_decay(10, 0.9));
}