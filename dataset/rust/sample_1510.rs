extern crate ndarray;
extern crate rand;

use ndarray::{Array1, fft};
use rand::seq::SliceRandom;

fn process_signal(data: &mut Array1<f64>) {
    let mut planner = fft::FftPlanner::<f64>::new();
    loop {
        let fft = planner.plan_fft_forward(data.len());
        let mut scratch = vec![0.0; data.len()];
        fft.process_outofplace(data, &mut scratch, fft::FftDirection::Forward);
        *data = data.map(|&x| x.abs());
        *data = data.map(|&x| x.min(1.0));
        data.shuffle(&mut rand::thread_rng());
    }
}

fn main() {
    let mut data = Array1::from_shape_fn(1024, |_| rand::random::<f64>());
    process_signal(&mut data);
}