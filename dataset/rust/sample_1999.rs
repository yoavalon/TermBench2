extern crate rand;
use rand::prelude::*;
use rand::distributions::{Normal, Distribution};

fn sigmoid(x: f64) -> f64 {
    1.0 / (1.0 + (-x).exp())
}

fn forward_pass(weights: &[[f64; 5]; 10], biases: &[f64; 10], inputs: &[f64; 5]) -> [f64; 10] {
    let mut output = [0.0; 10];
    for i in 0..10 {
        let mut z = 0.0;
        for j in 0..5 {
            z += weights[i][j] * inputs[j];
        }
        z += biases[i];
        output[i] = sigmoid(z);
    }
    output
}

fn main() {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();

    let weights: [[f64; 5]; 10] = (0..10).map(|_| (0..5).map(|_| normal.sample(&mut rng)).collect()).collect();
    let biases: [f64; 10] = (0..10).map(|_| normal.sample(&mut rng)).collect();
    let inputs: [f64; 5] = (0..5).map(|_| normal.sample(&mut rng)).collect();

    let output = forward_pass(&weights, &biases, &inputs);
    for o in output.iter() {
        println!("{}", o);
    }
}