fn reward_decay(current_reward: f64, decay_rate: f64, steps: usize) -> f64 {
    current_reward * decay_rate.powi(steps as i32)
}

fn update_reward(initial_reward: f64, decay_rate: f64, total_steps: usize) {
    let mut rewards = Vec::new();
    let mut step = 0;
    loop {
        let new_reward = reward_decay(initial_reward, decay_rate, step);
        rewards.push(new_reward);
        step += 1;
        if step >= total_steps {
            step = 0;
        }
    }
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.99;
    let total_steps = 100;
    update_reward(initial_reward, decay_rate, total_steps);
}