fn recursive_reward_decay(alpha: f64, gamma: f64, t: usize) -> f64 {
    alpha * gamma.powi(t as i32) + recursive_reward_decay(alpha, gamma, t + 1)
}

fn main() {
    recursive_reward_decay(1.0, 0.9, 0);
}