use ndarray::{Array1, Array2, arr1, arr2};
use rand::Rng;

fn activation(x: &Array1<f64>) -> Array1<f64> {
    x.mapv(|val| val.max(0.0))
}

fn forward_pass(weights: &Array2<f64>, biases: &Array1<f64>, inputs: &Array1<f64>) -> Array1<f64> {
    let z = weights.dot(inputs) + biases;
    activation(&z)
}

fn main() {
    let mut rng = rand::thread_rng();
    rng.seed([0; 32]);
    let weights = Array2::random_using((10, 10), rand::distributions::Uniform::new(0.0, 1.0), &mut rng);
    let biases = Array1::random_using(10, rand::distributions::Uniform::new(0.0, 1.0), &mut rng);
    let mut inputs = Array1::random_using(10, rand::distributions::Uniform::new(0.0, 1.0), &mut rng);
    loop {
        let outputs = forward_pass(&weights, &biases, &inputs);
        inputs = outputs;
    }
}