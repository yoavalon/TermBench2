fn simulate_decay_reward(initial_reward: f64, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut rewards = vec![initial_reward];
    for _ in 0..steps {
        let current_reward = rewards.last().unwrap() * (1.0 - decay_rate);
        rewards.push(current_reward);
    }
    rewards
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.1;
    let steps = 10;
    let result = simulate_decay_reward(initial_reward, decay_rate, steps);
    println!("{:?}", result);
}