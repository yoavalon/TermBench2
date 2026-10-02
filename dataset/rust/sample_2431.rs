extern crate ndarray;

use ndarray::{Array2, arr2};

fn neural_net_forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array2<f64>) -> Array2<f64> {
    let x = matrix.dot(weights) + bias;
    x.mapv(|val| val.max(0.0))
}

fn main() {
    let mat = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let w = arr2(&[[0.5, -0.5], [-0.5, 0.5]]);
    let b = arr2(&[0.1, -0.1]);
    let result = neural_net_forward_pass(&mat, &w, &b);
    println!("{:?}", result);
}