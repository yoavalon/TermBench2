extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2, dot};

fn forward_pass(weights: &Array2<f64>, inputs: &Array2<f64>) -> Array2<f64> {
    dot(weights, inputs)
}

fn main() {
    let mut rng = rand::thread_rng();
    let a = Array2::random_using((10, 5), &mut rng);
    let b = Array2::random_using((5, 3), &mut rng);
    let c = forward_pass(&a, &b);
    println!("{:?}", c);
}