fn sequence_reward_decay(steps: usize, decay_rate: f64) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut reward = 1.0;
    for _ in 0..steps {
        rewards.push(reward);
        reward *= decay_rate;
    }
    rewards
}

fn main() {
    let steps = 10;
    let decay_rate = 0.9;
    let result = sequence_reward_decay(steps, decay_rate);
    println!("{:?}", result);
}