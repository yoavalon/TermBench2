fn reward_decay(alpha: f64, gamma: f64, steps: usize) -> f64 {
    let mut reward = 1.0;
    for _ in 0..steps {
        reward *= alpha * gamma;
    }
    reward
}

fn main() {
    let alpha = 0.5;
    let gamma = 0.9;
    let steps = 10;
    let result = reward_decay(alpha, gamma, steps);
    println!("{}", result);
}