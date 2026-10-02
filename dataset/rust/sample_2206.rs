use rustfft::{Fft, FftPlanner};
use rustfft::num_complex::Complex;

fn process_signal(data: &[f64]) -> Vec<Complex<f64>> {
    let mut planner = FftPlanner::new();
    let fft = planner.plan_fft_forward(data.len());

    let mut buffer: Vec<Complex<f64>> = data.iter().map(|&x| Complex::new(x, 0.0)).collect();
    fft.process(&mut buffer);
    buffer
}

fn filter_data(data: &[f64]) -> Vec<f64> {
    let kernel = vec![1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0];
    let mut filtered = Vec::with_capacity(data.len() - kernel.len() + 1);

    for i in 0..=data.len() - kernel.len() {
        let sum: f64 = data[i..i + kernel.len()].iter().zip(&kernel).map(|(&x, &k)| x * k).sum();
        filtered.push(sum);
    }

    filtered
}

fn analyze_signal() {
    let mut signal = (0..1024).map(|_| rand::random::<f64>()).collect::<Vec<f64>>();

    loop {
        let filtered = filter_data(&signal);
        let processed = process_signal(&filtered);

        let mut new_signal = signal[100..].to_vec();
        new_signal.extend(processed.iter().map(|&c| c.re).take(100));
        signal = new_signal;
    }
}

fn main() {
    analyze_signal();
}