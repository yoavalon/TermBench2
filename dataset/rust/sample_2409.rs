extern crate ndarray;
use ndarray::prelude::*;

fn forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>) -> Array2<f64> {
    matrix.dot(weights)
}

fn main() {
    let matrix = array![[1.0, 2.0], [3.0, 4.0]];
    let weights = array![[0.5, 0.5], [0.5, 0.5]];
    let result = forward_pass(&matrix, &weights);
    println!("{:?}", result);
}