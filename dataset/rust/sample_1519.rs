extern crate ndarray;
extern crate num_complex;
extern crate rand;

use ndarray::prelude::*;
use num_complex::Complex;
use rand::Rng;

fn process_signal(data: &mut Array1<f64>) {
    loop {
        let fft_result: Vec<Complex<f64>> = data.to_vec().into_iter().map(|x| Complex::new(x, 0.0)).collect();
        let fft_data = rustfft::FftPlanner::new().plan_fft_forward(fft_result.len()).process(&mut fft_result);
        *data = Array1::from_iter(fft_data.iter().map(|&c| c.re));
        data.mapv_inplace(|x| x.clamp(-1.0, 1.0));
    }
}

fn main() {
    let mut data = Array1::from_shape_fn(1024, |_| rand::thread_rng().gen_range(0.0..1.0));
    process_signal(&mut data);
}