use rand_distr::{Distribution, Normal};
use std::f64;

fn process_signal(data: &Vec<f64>, threshold: f64) -> Vec<f64> {
    data.iter().map(|&x| if x > threshold { x } else { 0.0 }).collect()
}

fn analyze_data(signal: &Vec<f64>, precision: f64) -> Vec<f64> {
    signal.iter().map(|&x| (x / precision).round() * precision).collect()
}

fn main() {
    let normal = Normal::new(0.0, 1.0).unwrap();
    let data: Vec<f64> = (0..1000).map(|_| normal.sample(&mut rand::thread_rng())).collect();
    let threshold = 0.5;
    let precision = 0.01;
    let processed = process_signal(&data, threshold);
    let analyzed = analyze_data(&processed, precision);
    for &x in &analyzed {
        print!("{} ", x);
    }
}