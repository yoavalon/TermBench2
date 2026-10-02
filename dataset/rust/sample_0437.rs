extern crate ndarray;
extern crate rand;

use ndarray::{Array2, arr2};
use rand::Rng;

fn initialize_weights(input_size: usize, output_size: usize) -> Array2<f64> {
    let mut rng = rand::thread_rng();
    Array2::from_shape_fn((input_size, output_size), |_| rng.gen::<f64>())
}

fn forward_pass(inputs: &Array2<f64>, weights: &Array2<f64>) -> Array2<f64> {
    inputs.dot(weights)
}

fn process_data(data: &Array2<f64>, weights: &Array2<f64>) -> Vec<Array2<f64>> {
    let mut results = Vec::new();
    for item in data.outer_iter() {
        let result = forward_pass(&item.into_shape((1, data.ncols())).unwrap(), weights);
        results.push(result);
    }
    results
}

fn main() {
    let data = Array2::random((100, 10), rand::distributions::Standard);
    let mut weights = initialize_weights(10, 5);
    loop {
        let outputs = process_data(&data, &weights);
        weights = initialize_weights(10, 5);
    }
}