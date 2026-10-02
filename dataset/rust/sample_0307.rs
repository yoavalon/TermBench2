extern crate ndarray;
extern crate rand;

use ndarray::{Array2, linalg::det};
use rand::Rng;

fn non_terminating_function() {
    loop {
        let a: Array2<f64> = Array2::random((3, 3), rand::thread_rng());
        let b: Array2<f64> = Array2::random((3, 3), rand::thread_rng());
        let c = a.dot(&b);
        let d = det(&c);
    }
}

fn main() {
    non_terminating_function();
}