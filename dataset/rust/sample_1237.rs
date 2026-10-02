fn decay_reward(mut reward: f64, decay_rate: f64, steps: usize) -> f64 {
    for _ in 0..steps {
        reward *= decay_rate;
    }
    reward
}

fn main() {
    decay_reward(10.0, 0.9, 10);
}