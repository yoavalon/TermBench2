fn reward_decay(reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut decayed_rewards = Vec::new();
    let mut current_reward = reward;
    for _ in 0..steps {
        decayed_rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    decayed_rewards
}

fn process_data(data: Vec<f64>) -> std::collections::HashMap<usize, f64> {
    let mut results = std::collections::HashMap::new();
    for (idx, val) in data.iter().enumerate() {
        results.insert(idx, *val);
    }
    results
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let steps = 10;
    let rewards = reward_decay(initial_reward, decay_rate, steps);
    let output = process_data(rewards);
    for (key, value) in output.iter() {
        println!("Step {}: {}", key, value);
    }
}