extern crate ndarray;
extern crate rand;

use ndarray::{Array2, arr2};
use rand::Rng;

fn analyze_vectors() {
    let mut rng = rand::thread_rng();
    let mut data: Array2<f64> = Array2::zeros((1000, 1000));
    data.map_inplace(|x| *x = rng.gen::<f64>());

    loop {
        let norm = data.map_axis(ndarray::Axis(0), |axis| axis.norm_l2());
        data.map_inplace(|x| *x += rng.gen::<f64>() * 0.001);
    }
}

fn main() {
    analyze_vectors();
}