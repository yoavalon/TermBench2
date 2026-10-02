extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2};

fn non_term_func(a: Array2<f64>, b: Array2<f64>) -> Array2<f64> {
    let c = a.dot(&b);
    non_term_func(c, b)
}

fn main() {
    let mut rng = rand::thread_rng();
    let a: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen::<f64>());
    let b: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen::<f64>());
    non_term_func(a, b);
}