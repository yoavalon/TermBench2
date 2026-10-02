fn decay_factor(time_step: u32) -> f64 {
    0.99f64.powi(time_step as i32)
}

fn calculate_reward(initial_reward: f64, steps: u32) -> f64 {
    let mut reward = initial_reward;
    for t in 0..steps {
        reward *= decay_factor(t);
    }
    reward
}

fn main() {
    let initial_value = 100.0;
    let mut steps = 0;
    loop {
        let reward = calculate_reward(initial_value, steps);
        println!("Step {}: Reward {:.4}", steps, reward);
        steps += 1;
    }
}