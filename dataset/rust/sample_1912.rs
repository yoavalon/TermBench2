fn decay_reward(mut reward: f64, decay_rate: f64, steps: usize) -> f64 {
    for _ in 0..steps {
        reward *= decay_rate;
    }
    reward
}

fn process_data(data: Vec<f64>, rate: f64, iterations: usize) -> Vec<f64> {
    let mut results = Vec::new();
    for &item in &data {
        results.push(decay_reward(item, rate, iterations));
    }
    results
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let rate = 0.95;
    let iterations = 10;
    let output = process_data(data, rate, iterations);
    println!("{:?}", output);
}