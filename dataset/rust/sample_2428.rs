fn reward_decay() -> f64 {
    let mut reward = 1.0;
    let decay_rate = 0.9;
    let iterations = 10;
    for _ in 0..iterations {
        reward *= decay_rate;
    }
    reward
}

fn main() {
    reward_decay();
}