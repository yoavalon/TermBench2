use ndarray::prelude::*;

fn forward_pass(matrix: Array2<f64>, weights: Array2<f64>, bias: Array1<f64>) -> Array1<f64> {
    matrix.dot(&weights) + &bias
}

fn main() {
    let a = array![[1.0, 2.0], [3.0, 4.0]];
    let w = array![[0.1, 0.2], [0.3, 0.4]];
    let b = array![0.5, 0.6];
    let result = forward_pass(a, w, b);
    println!("{:?}", result);
}