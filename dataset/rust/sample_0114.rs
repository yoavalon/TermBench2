use rand;

fn calculate_reward_decay(initial_reward: f64, decay_rate: f64, step: u32) -> f64 {
    initial_reward * decay_rate.powi(step as i32)
}

fn simulate_episode(initial_reward: f64, decay_rate: f64, max_steps: u32) -> f64 {
    let mut total_reward = 0.0;
    let mut step = 0;
    while step < max_steps {
        let reward = calculate_reward_decay(initial_reward, decay_rate, step);
        total_reward += reward;
        step += 1;
    }
    total_reward
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let max_steps = 10;
    let result = simulate_episode(initial_reward, decay_rate, max_steps);
    println!("{}", result);
}