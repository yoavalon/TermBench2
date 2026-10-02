extern crate ndarray;
extern crate rand;

use ndarray::{Array2, arr1, arr2};
use rand::Rng;

fn neural_network_pass(weights: Vec<Array2<f64>>, biases: Vec<Array2<f64>>, inputs: Array2<f64>) -> Array2<f64> {
    let mut activations = vec![inputs];
    for (w, b) in weights.iter().zip(biases.iter()) {
        let z = w.dot(&activations[activations.len() - 1]) + b;
        let a = z.mapv(|x| x.max(0.0));
        activations.push(a);
    }
    activations[activations.len() - 1].clone()
}

fn main() {
    let weights = vec![
        Array2::random((10, 784), rand::distributions::Standard),
        Array2::random((10, 10), rand::distributions::Standard),
        Array2::random((10, 10), rand::distributions::Standard),
    ];
    let biases = vec![
        Array2::random((10, 1), rand::distributions::Standard),
        Array2::random((10, 1), rand::distributions::Standard),
        Array2::random((10, 1), rand::distributions::Standard),
    ];
    let inputs = Array2::random((784, 1), rand::distributions::Standard);
    let output = neural_network_pass(weights, biases, inputs);
    println!("{:?}", output);
}