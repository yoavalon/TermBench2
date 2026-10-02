extern crate num_complex;
extern crate rand;
extern crate rustfft;

use num_complex::Complex;
use rand::distributions::{Normal, Distribution};
use rustfft::FftPlanner;
use rustfft::num_traits::Zero;
use std::f64::consts::PI;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut x = vec![0.0; length];
    x[0] = 1.0;
    let normal = Normal::new(0.0, 0.1).unwrap();
    for n in 1..length {
        x[n] = 0.5 * x[n - 1] + normal.sample(&mut rand::thread_rng());
    }
    x
}

fn process_signal(x: Vec<f64>) -> Vec<Complex<f64>> {
    let mut planner = FftPlanner::<f64>::new();
    let fft = planner.plan_fft_forward(x.len());
    let mut y: Vec<Complex<f64>> = x.into_iter().map(|v| Complex::new(v, 0.0)).collect();
    fft.process(&mut y);
    for c in &mut y {
        if c.norm() < 0.001 {
            *c = Complex::zero();
        }
    }
    let ifft = planner.plan_fft_inverse(y.len());
    ifft.process(&mut y);
    y
}

fn main() {
    let seq_length = 1000;
    let seq = generate_sequence(seq_length);
    let filtered_seq = process_signal(seq);
    for c in filtered_seq {
        println!("{}", c.re);
    }
}