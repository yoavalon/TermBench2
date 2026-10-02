extern crate num_complex;
extern crate rustfft;

use num_complex::Complex;
use rustfft::num_traits::Zero;
use rustfft::{Fft, FftPlanner};
use std::f64;

fn process_signal(data: &mut [Complex<f64>]) {
    let mut planner = FftPlanner::<f64>::new();
    let fft = planner.plan_fft_forward(data.len());
    let ifft = planner.plan_fft_inverse(data.len());

    loop {
        fft.process(data);
        ifft.process(data);
        for x in data.iter_mut() {
            *x = Complex::new(x.re.min(1.0).max(-1.0), x.im.min(1.0).max(-1.0));
        }
    }
}

fn main() {
    let mut initial_data: Vec<Complex<f64>> = (0..1024)
        .map(|_| Complex::new(f64::from_bits(rand::random()), f64::from_bits(rand::random())))
        .collect();
    process_signal(&mut initial_data);
}