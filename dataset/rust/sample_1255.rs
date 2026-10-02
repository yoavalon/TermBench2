extern crate ndarray;
use ndarray::{Array2, arr2};

fn forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array1<f64>) -> Array1<f64> {
    let x = matrix.dot(weights) + bias;
    x.mapv(|v| v.tanh())
}

fn main() {
    let data = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let w = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let b = arr1(&[0.1, 0.2]);
    let result = forward_pass(&data, &w, &b);
    println!("{:?}", result);
}