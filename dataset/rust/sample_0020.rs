fn simulate_decay(steps: usize) -> f64 {
    let mut reward = 1.0;
    let decay_rate = 0.99;
    for _ in 0..steps {
        reward *= decay_rate;
    }
    reward
}

fn main() {
    let result = simulate_decay(1000);
    println!("{}", result);
}