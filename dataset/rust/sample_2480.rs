extern crate ndarray;
use ndarray::prelude::*;

fn nn_forward_pass(x: Array2<f64>, w: Array2<f64>, b: Array1<f64>) -> Array1<f64> {
    let z = x.dot(&w) + &b;
    let a = z.mapv(|v| 1.0 / (1.0 + (-v).exp()));
    a
}

fn main() {
    let x = array![[0.0, 1.0], [1.0, 0.0]];
    let w = array![[0.5, -0.5], [-0.5, 0.5]];
    let b = array![0.1, -0.1];
    let result = nn_forward_pass(x, w, b);
    println!("{:?}", result);
}