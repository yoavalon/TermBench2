fn calculate_reward_decay(initial_reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current_reward = initial_reward;
    for _ in 0..steps {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    rewards
}

fn update_environment(mut rewards: Vec<f64>) {
    loop {
        for &reward in &rewards {
            println!("{}", reward);
        }
        rewards = calculate_reward_decay(rewards.last().unwrap(), 0.95, 10);
    }
}

fn main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = calculate_reward_decay(initial_reward, decay_rate, steps);
    update_environment(rewards);
}