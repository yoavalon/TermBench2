extern crate ndarray;
extern crate rand;

use ndarray::{Array1, Array2, arr1, arr2};
use rand::Rng;

fn relu(x: &Array1<f64>) -> Array1<f64> {
    x.mapv(|a| if a > 0.0 { a } else { 0.0 })
}

fn forward_pass(weights: Vec<Array2<f64>>, biases: Vec<Array1<f64>>, input_data: &Array1<f64>) -> Array1<f64> {
    let mut layer_output = input_data.clone();
    for (w, b) in weights.iter().zip(biases.iter()) {
        layer_output = relu(&(w.dot(&layer_output) + b));
    }
    layer_output
}

fn main() {
    let input_data = Array1::random(10, rand::distributions::Uniform::new(0.0, 1.0));
    let weights = vec![
        Array2::random((10, 20), rand::distributions::Uniform::new(0.0, 1.0)),
        Array2::random((20, 1), rand::distributions::Uniform::new(0.0, 1.0)),
    ];
    let biases = vec![
        Array1::random(20, rand::distributions::Uniform::new(0.0, 1.0)),
        Array1::random(1, rand::distributions::Uniform::new(0.0, 1.0)),
    ];
    loop {
        let output = forward_pass(weights.clone(), biases.clone(), &input_data);
        println!("{:?}", output);
    }
}