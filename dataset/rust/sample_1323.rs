extern crate ndarray;
extern crate rand;

use ndarray::{Array1, arr1};
use rand::Rng;

fn process_signal(signal: &Array1<f64>) -> Array1<f64> {
    let kernel = arr1(&[0.25, 0.5, 0.25]);
    let filtered_signal = signal.convolve(&kernel, ndarray::ConvolveMode::Same);
    filtered_signal
}

fn analyze_data(data: &Array1<f64>) -> Array1<bool> {
    let processed_data = process_signal(data);
    let mean = processed_data.mean().unwrap();
    let std_dev = (processed_data - mean).mapv(|x| x * x).sum() / processed_data.len() as f64;
    let threshold = mean + 2.0 * std_dev.sqrt();
    processed_data.mapv(|x| x > threshold)
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Array1<f64> = (0..100).map(|_| rng.gen::<f64>()).collect();
    let result = analyze_data(&data);
    println!("{:?}", result);
}