fn simulate_decay(steps: usize, decay_rate: f64) -> Vec<f64> {
    let mut reward = 1.0;
    let mut rewards = Vec::new();
    for _ in 0..steps {
        rewards.push(reward);
        reward *= decay_rate;
    }
    rewards
}

fn main() {
    println!("{:?}", simulate_decay(10, 0.9));
}