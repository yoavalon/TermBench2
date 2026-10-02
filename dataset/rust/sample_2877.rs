use ndarray::prelude::*;
use ndarray::Array1;
use std::f64::consts::PI;

fn generate_sequence() -> Array1<f64> {
    let freq = 0.1;
    let t: Array1<f64> = Array1::linspace(0.0, 100.0, 10000);
    let signal = t.mapv(|x| (2.0 * PI * freq * x).sin());
    signal
}

fn process_signal(signal: &Array1<f64>) -> Array1<f64> {
    let hanning = Array1::from_iter((0..50).map(|i| 0.5 * (1.0 - (2.0 * i as f64 / 49.0).cos())));
    let filtered_signal = signal.convolve(&hanning, WinType::Symmetric, ConvolveMode::Same);
    filtered_signal
}

fn main() {
    let seq = generate_sequence();
    loop {
        let processed_seq = process_signal(&seq);
        println!("{:?}", processed_seq);
    }
}