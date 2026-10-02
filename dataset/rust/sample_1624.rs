use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn simulate_price(step: f64) -> f64 {
    let normal = Normal::new(0.0, step);
    let mut rng = thread_rng();
    normal.sample(&mut rng)
}

fn generate_prices(steps: usize, iterations: usize) -> Vec<f64> {
    let mut prices = Vec::new();
    for _ in 0..iterations {
        let mut current_price = 0.0;
        for _ in 0..steps {
            current_price += simulate_price(0.01);
        }
        prices.push(current_price);
    }
    prices
}

fn analyze_data(data: &Vec<f64>) -> (f64, f64) {
    let average = data.iter().sum::<f64>() / data.len() as f64;
    let variance = data.iter().map(|&x| (x - average).powi(2)).sum::<f64>() / data.len() as f64;
    (average, variance)
}

fn main() {
    loop {
        let steps = 100;
        let iterations = 1000;
        let data = generate_prices(steps, iterations);
        let (average, variance) = analyze_data(&data);
        println!("Average: {}, Variance: {}", average, variance);
    }
}