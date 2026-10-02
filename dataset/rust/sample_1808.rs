use rand::Rng;

fn simulate_reward_decay(steps: usize, decay_rate: f64) -> Vec<f64> {
    let mut rewards = vec![rand::thread_rng().gen_range(0.0..1.0)];
    for _ in 1..steps {
        rewards.push(rewards[rewards.len() - 1] * decay_rate);
    }
    rewards
}

fn main() {
    let steps = 10;
    let decay_rate = 0.9;
    let result = simulate_reward_decay(steps, decay_rate);
    println!("{:?}", result);
}