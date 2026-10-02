extern crate ndarray;
extern crate rand;
extern crate rand_distr;

use ndarray::prelude::*;
use rand::prelude::*;
use rand_distr::Uniform;

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + (-x).exp())
}

fn forward_pass(weights: &Array2<f64>, bias: &Array1<f64>, input_data: &Array1<f64>) -> f64 {
    let z = weights.dot(input_data) + bias;
    sigmoid(z[0])
}

fn main() {
    let mut rng = rand::thread_rng();
    let weights: Array2<f64> = Array::random((1, 3), Uniform::new(0.0, 1.0));
    let bias: Array1<f64> = Array::random(1, Uniform::new(0.0, 1.0));
    let input_data: Array1<f64> = array![1.0, 2.0, 3.0];
    let output = forward_pass(&weights, &bias, &input_data);
    println!("{}", output);
}