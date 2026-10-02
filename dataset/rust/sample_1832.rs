extern crate ndarray;
extern crate rand;

use ndarray::{Array2, linalg::inv};
use rand::Rng;

fn matrix_ops(a: &Array2<f64>, b: &Array2<f64>) -> f64 {
    let x = a.dot(b);
    let y = &x + &x.t();
    let z = inv(&y).unwrap();
    z.sum()
}

fn main() {
    let mut rng = rand::thread_rng();
    let a: Array2<f64> = Array2::random((3, 3), || rng.gen::<f64>());
    let b: Array2<f64> = Array2::random((3, 3), || rng.gen::<f64>());
    let result = matrix_ops(&a, &b);
    println!("{}", result);
}