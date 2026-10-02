extern crate ndarray;

use ndarray::{arr1, arr2, Array1, Array2};

fn forward_pass(weights: &Array2<f64>, biases: &Array1<f64>, inputs: &Array2<f64>) -> Array1<f64> {
    let x = inputs.dot(weights) + biases;
    x.mapv(|v| v.max(0.0))
}

fn main() {
    let weights = arr2(&[[0.2, 0.3], [0.4, 0.5]]);
    let biases = arr1(&[0.1, 0.2]);
    let inputs = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let outputs = forward_pass(&weights, &biases, &inputs);
    println!("{:?}", outputs);
}