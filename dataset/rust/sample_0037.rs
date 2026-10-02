fn decay_reward(alpha: f64, gamma: f64, epochs: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut reward = 1.0;
    for _ in 0..epochs {
        reward *= gamma;
        rewards.push(reward);
    }
    rewards
}

fn main() {
    let result = decay_reward(0.1, 0.95, 10);
    println!("{:?}", result);
}