extern crate ndarray;
extern crate rand;

use ndarray::{Array1, arr1};
use rand::distributions::{Normal, Distribution};

fn generate_signal(length: usize) -> Array1<f64> {
    let normal = Normal::new(0.0, 1.0);
    let mut rng = rand::thread_rng();
    let mut signal = Array1::zeros(length);
    for i in 0..length {
        signal[i] = normal.sample(&mut rng);
    }
    signal
}

fn mutate_signal(signal: &Array1<f64>, factor: f64) -> Array1<f64> {
    signal.mapv(|x| x * factor)
}

fn process_signal(signal: &Array1<f64>, mutation_factor: f64) -> Array1<complex::Complex<f64>> {
    let mutated_signal = mutate_signal(signal, mutation_factor);
    rustfft::algorithm::FFT::<f64>::new(rustfft::num_samples::FftNumSamples::new(signal.len()))
        .unwrap()
        .process(&mut mutated_signal.view(), false)
        .unwrap()
}

fn main() {
    let length = 1024;
    let factor = 0.5;
    let signal = generate_signal(length);
    let processed_signal = process_signal(&signal, factor);
    println!("{:?}", processed_signal);
}