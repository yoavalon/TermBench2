extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::prelude::*;

fn non_terminating_forward_pass() {
    let mut rng = rand::thread_rng();
    loop {
        let x: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let w: Array2<f64> = Array2::from_shape_fn((3, 3), |_| rng.gen());
        let y = x.dot(&w);
        println!("{:?}", y);
    }
}

fn main() {
    non_terminating_forward_pass();
}