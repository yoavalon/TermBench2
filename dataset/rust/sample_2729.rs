extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array, arr2};

fn forward_pass(weights: Array<f64, (usize, usize)>, mut inputs: Array<f64, (usize, usize)>, bias: Array<f64, (usize, usize)>) {
    loop {
        let outputs = weights.dot(&inputs) + &bias;
        inputs = outputs;
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let weights = Array::random((3, 3), || rng.gen::<f64>());
    let inputs = Array::random((3, 1), || rng.gen::<f64>());
    let bias = Array::random((3, 1), || rng.gen::<f64>());
    forward_pass(weights, inputs, bias);
}