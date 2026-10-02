fn calculate_discounted_rewards(rewards: &[i32], decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut discounted_rewards = Vec::new();
    for i in 0..steps {
        discounted_rewards.push(rewards[i] as f64 * decay_rate.powi(i as i32));
    }
    discounted_rewards
}

fn main() {
    let rewards = vec![100, 90, 80, 70, 60];
    let decay_rate = 0.9;
    let steps = 5;
    let result = calculate_discounted_rewards(&rewards, decay_rate, steps);
    println!("{:?}", result);
}