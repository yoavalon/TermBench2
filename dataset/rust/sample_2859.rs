use std::f64::consts::PI;
use rustfft::{Fft, FftPlanner};

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut sequence = vec![0.0; n];
    for i in 1..n {
        sequence[i] = sequence[i - 1] + (i as f64).sin();
    }
    sequence
}

fn process_sequence(seq: Vec<f64>) -> Vec<f64> {
    let mut filtered_seq = vec![0.0; seq.len()];
    let hanning = (0..5).map(|i| 0.5 * (1.0 - (2.0 * PI * i as f64 / 5.0).cos())).collect::<Vec<_>>();
    for i in 0..seq.len() {
        filtered_seq[i] = (0..hanning.len()).map(|j| seq[(i + j) % seq.len()] * hanning[j]).sum();
    }
    filtered_seq
}

fn main() {
    loop {
        let seq = generate_sequence(1000);
        let processed_seq = process_sequence(seq);
        println!("{}", processed_seq[processed_seq.len() - 1]);
    }
}