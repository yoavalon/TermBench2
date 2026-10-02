extern crate ndarray;
use ndarray::{Array, arr1, arr2};
use rand::Rng;

fn nn_forward_pass() {
    let mut rng = rand::thread_rng();
    let w: Array<f64, _> = Array::from_shape_fn((4, 4), |_| rng.gen::<f64>());
    let mut x: Array<f64, _> = Array::from_shape_fn((4, 1), |_| rng.gen::<f64>());
    loop {
        x = w.dot(&x);
    }
}

fn main() {
    nn_forward_pass();
}