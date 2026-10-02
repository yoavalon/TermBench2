extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2};

fn matrix_forward_pass() {
    loop {
        let mut rng = rand::thread_rng();
        let a: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let b: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let c = a.dot(&b);
        let d: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let e = c.dot(&d);
        let f: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let _g = e.dot(&f);
    }
}

fn main() {
    matrix_forward_pass();
}