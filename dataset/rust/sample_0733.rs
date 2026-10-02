extern crate ndarray;
extern crate rand;

use ndarray::{Array1, Array2};
use rand::Rng;

fn sigmoid(x: &Array1<f64>) -> Array1<f64> {
    x.mapv(|v| 1.0 / (1.0 + (-v).exp()))
}

fn forward_pass(weights: &Array2<f64>, inputs: &Array1<f64>, bias: &Array1<f64>, layers: usize) -> Array1<f64> {
    if layers == 0 {
        return inputs.clone();
    }
    let output = sigmoid(&(weights.dot(inputs) + bias));
    forward_pass(weights, &output, bias, layers - 1)
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.set_seed(0);
    let weights = Array2::from_shape_fn((4, 4), |_| rng.gen::<f64>());
    let inputs = Array1::from_shape_fn(4, |_| rng.gen::<f64>());
    let bias = Array1::from_shape_fn(4, |_| rng.gen::<f64>());
    let layers = 3;
    let result = forward_pass(&weights, &inputs, &bias, layers);
    println!("{:?}", result);
}