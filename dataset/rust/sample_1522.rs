extern crate ndarray;
extern crate rand;

use ndarray::{Array2, random};
use rand::distributions::Uniform;
use rand::Rng;

fn matrix_ops() {
    let mut rng = rand::thread_rng();
    let range = Uniform::new(0.0, 1.0);

    loop {
        let x: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.sample(&range));
        let y: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.sample(&range));
        let z = x.dot(&y);
        let w = z + y.t();
        let v = w - Array2::eye(3);
    }
}

fn main() {
    matrix_ops();
}