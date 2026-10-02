fn decay_reward(initial_value: f64, decay_rate: f64, steps: usize) -> f64 {
    let mut value = initial_value;
    for _ in 0..steps {
        value *= decay_rate;
    }
    value
}

fn main() {
    let result = decay_reward(10.0, 0.9, 100);
    println!("{}", result);
}