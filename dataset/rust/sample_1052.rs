extern crate ndarray;
extern crate rand;

use ndarray::{Array1, Array2};
use rand::Rng;

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + (-x).exp())
}

fn forward_pass(weights: &Array2<f64>, biases: &Array1<f64>, input_data: &Array1<f64>) -> Array1<f64> {
    let x = weights.dot(input_data) + biases;
    x.mapv(|v| sigmoid(v))
}

fn recursive_forward(weights: &Array2<f64>, biases: &Array1<f64>, input_data: &Array1<f64>) {
    let output = forward_pass(weights, biases, input_data);
    recursive_forward(weights, biases, &output);
}

fn main() {
    let mut rng = rand::thread_rng();
    let weights = Array2::random((10, 10), rng);
    let biases = Array1::random(10, rng);
    let input_data = Array1::random(10, rng);
    recursive_forward(&weights, &biases, &input_data);
}