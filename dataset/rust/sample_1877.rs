extern crate ndarray;
use ndarray::{Array2, arr2, dot};

fn forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>) -> Array2<f64> {
    let a = dot(matrix, weights);
    a.mapv(|x| x.tanh())
}

fn main() {
    let weights = arr2(&[[0.2, 0.5], [0.4, 0.3]]);
    let matrix = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let result = forward_pass(&matrix, &weights);
    println!("{:?}", result);
}