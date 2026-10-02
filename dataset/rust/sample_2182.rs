extern crate ndarray;
extern crate rand;

use ndarray::prelude::*;
use rand::Rng;

fn main() {
    let mut rng = rand::thread_rng();
    let mut signal: Array1<f64> = Array::from_iter(rng.gen_iter::<f64>().take(1024));
    let filter_coeff: Array1<f64> = arr1(&[0.25, 0.5, 0.25]);

    loop {
        signal = signal.convolve(&filter_coeff, ConvolveKind::Same);
    }
}