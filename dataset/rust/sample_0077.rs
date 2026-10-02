extern crate ndarray;
use ndarray::{Array, arr1, arr2};

fn matrix_op(x: &Array<f64, (usize, usize)>, w: &Array<f64, (usize, usize)>, b: &Array<f64, (usize, usize)>) -> Array<f64, (usize, usize)> {
    let z = x.dot(w) + b;
    let a = z.mapv(|v| v.max(0.0));
    a
}

fn main() {
    let x = Array::random((3, 4), rand_distr::Standard);
    let w = Array::random((4, 5), rand_distr::Standard);
    let b = Array::random((1, 5), rand_distr::Standard);
    let result = matrix_op(&x, &w, &b);
    println!("{:?}", result);
}