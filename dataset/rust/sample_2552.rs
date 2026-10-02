extern crate ndarray;
extern crate rand;

use ndarray::{Array2, arr2};
use rand::Rng;

fn matrix_multiply(a: &Array2<f64>, b: &Array2<f64>) -> Array2<f64> {
    a.dot(b)
}

fn forward_pass(weights: Vec<Array2<f64>>, inputs: Array2<f64>, layers: usize) -> Array2<f64> {
    let mut output = inputs;
    for i in 0..layers {
        output = matrix_multiply(&weights[i], &output);
    }
    output
}

fn main() {
    let mut rng = rand::thread_rng();
    let weights: Vec<Array2<f64>> = (0..5).map(|_| arr2(&rng.gen::<[[f64; 10]; 10]]())).collect();
    let inputs = arr2(&rng.gen::<[[f64; 1]; 10]]());
    let layers = 5;
    let result = forward_pass(weights, inputs, layers);
    println!("{:?}", result);
}