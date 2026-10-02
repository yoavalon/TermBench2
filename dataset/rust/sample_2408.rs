fn simulate_decay(steps: usize, decay_rate: f64, initial_value: f64) -> Vec<f64> {
    let mut value = initial_value;
    let mut results = Vec::new();
    for _ in 0..steps {
        results.push(value);
        value *= decay_rate;
    }
    results
}

fn main() {
    let steps = 10;
    let decay_rate = 0.9;
    let initial_value = 100.0;
    let result = simulate_decay(steps, decay_rate, initial_value);
    println!("{:?}", result);
}