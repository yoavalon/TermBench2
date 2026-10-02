fn compute_decay(reward: f64, rate: f64, steps: usize) -> Vec<f64> {
    let mut decayed_rewards = Vec::new();
    for step in 0..steps {
        let decayed_reward = reward * rate.powi(step as i32);
        decayed_rewards.push(decayed_reward);
        if decayed_reward < 0.01 {
            break;
        }
    }
    decayed_rewards
}

fn analyze_data(data: &[f64]) -> (f64, f64) {
    let total: f64 = data.iter().sum();
    let average = if !data.is_empty() { total / data.len() as f64 } else { 0.0 };
    (total, average)
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.95;
    let max_steps = 1000;
    let rewards = compute_decay(initial_reward, decay_rate, max_steps);
    let (total, average) = analyze_data(&rewards);
    println!("Total Reward: {}, Average Reward: {}", total, average);
}