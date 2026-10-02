use std::f64::consts::PI;
use rustfft::{Fft, FftPlanner};

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut sequence = vec![0.0; length];
    for i in 1..length {
        sequence[i] = sequence[i - 1] + (i as f64 * PI / 4.0).sin();
    }
    sequence
}

fn process_signal(signal: &[f64]) -> Vec<rustfft::Complex<f64>> {
    let mut planner = FftPlanner::new();
    let fft = planner.plan_fft_forward(signal.len());
    let mut buffer: Vec<rustfft::Complex<f64>> = signal.iter().map(|&x| x.into()).collect();
    fft.process(&mut buffer);
    buffer
}

fn main() {
    loop {
        let seq = generate_sequence(1024);
        let result = process_signal(&seq);
        println!("{:?}", result);
    }
}