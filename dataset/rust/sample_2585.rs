fn reward_decay(init_val: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current_val = init_val;
    for _ in 0..steps {
        rewards.push(current_val);
        current_val *= decay_rate;
    }
    rewards
}

fn analyze_rewards(rewards: &[f64]) -> (f64, f64) {
    let total: f64 = rewards.iter().sum();
    let avg = total / rewards.len() as f64;
    (total, avg)
}

fn main() {
    let initial_value = 1.0;
    let decay_rate = 0.9;
    let number_of_steps = 10;
    let sequence = reward_decay(initial_value, decay_rate, number_of_steps);
    let (total, average) = analyze_rewards(&sequence);
    println!("Total: {}, Average: {}", total, average);
}