use rand::Rng;

fn simulate_episode(decay_factor: f64) -> impl Iterator<Item = (f64, usize)> {
    let mut total_reward = 0.0;
    let mut current_reward = 1.0;
    let mut step = 0;
    std::iter::from_fn(move || {
        step += 1;
        total_reward += current_reward;
        current_reward *= decay_factor;
        Some((total_reward, step))
    })
}

fn main() {
    let decay_factor = 0.95;
    for (total_reward, step) in simulate_episode(decay_factor) {
        println!("Step {}: Total Reward {}", step, total_reward);
    }
}