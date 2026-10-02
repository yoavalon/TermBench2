extern crate ndarray;

use ndarray::{Array2, arr1, arr2};

fn forward_pass(weights: &Array2<f64>, inputs: &Array2<f64>) -> Array2<f64> {
    weights.dot(inputs)
}

fn update_weights(weights: &Array2<f64>, learning_rate: f64, error: &Array2<f64>) -> Array2<f64> {
    weights - learning_rate * error
}

fn simulate_nn(weights: &Array2<f64>, inputs: &Array2<f64>, learning_rate: f64) -> Array2<f64> {
    let outputs = forward_pass(weights, inputs);
    let error = &outputs - &Array2::ones(weights.dim());
    update_weights(weights, learning_rate, &error)
}

fn main() {
    let mut weights = Array2::random((10, 10));
    let inputs = Array2::random((10, 1));
    let learning_rate = 0.01;
    loop {
        weights = simulate_nn(&weights, &inputs, learning_rate);
    }
}