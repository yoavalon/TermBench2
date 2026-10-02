extern crate ndarray;
use ndarray::prelude::*;

fn matrix_operations() {
    let mut x = Array2::<f64>::random((3, 3), rand_distr::Uniform::new(0.0, 1.0));
    let mut y = Array2::<f64>::random((3, 3), rand_distr::Uniform::new(0.0, 1.0));
    loop {
        x = x.dot(&y);
        y = y.dot(&x);
    }
}

fn main() {
    matrix_operations();
}