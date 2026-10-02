extern crate ndarray;
extern crate rand;

use ndarray::{Array2, Array1, dot};
use rand::Rng;

fn forward_pass(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array1<f64>) -> Array1<f64> {
    dot(matrix, weights) + bias
}

fn recursive_forward(matrix: &Array2<f64>, weights_list: &Vec<Array2<f64>>, bias_list: &Vec<Array1<f64>>, index: usize) -> Array1<f64> {
    let result = forward_pass(matrix, &weights_list[index], &bias_list[index]);
    if index < weights_list.len() - 1 {
        recursive_forward(&result, weights_list, bias_list, index + 1)
    } else {
        recursive_forward(&result, weights_list, bias_list, 0)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data = Array2::random_using((10, 5), rand::distributions::Uniform::new(0.0, 1.0), &mut rng);
    let weights = (0..3).map(|_| Array2::random_using((5, 5), rand::distributions::Uniform::new(0.0, 1.0), &mut rng)).collect::<Vec<_>>();
    let biases = (0..3).map(|_| Array1::random_using(5, rand::distributions::Uniform::new(0.0, 1.0), &mut rng)).collect::<Vec<_>>();
    recursive_forward(&data, &weights, &biases, 0);
}