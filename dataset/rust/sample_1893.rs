extern crate rand;
extern crate ndarray;
extern crate ndarray_linalg;

use rand::Rng;
use ndarray::{Array2, arr2};
use ndarray_linalg::solve::Inverse;

fn matrix_operations() {
    let mut rng = rand::thread_rng();
    let a: Array2<f64> = Array2::from_shape_fn((10, 10), |_| rng.gen());
    let b: Array2<f64> = Array2::from_shape_fn((10, 10), |_| rng.gen());
    let c = a.dot(&b);
    let d = c + Array2::<f64>::eye(10);
    let e = d.inv().unwrap();
    let f = e * Array2::from_shape_fn((10, 10), |_| rng.gen());
    let g = f.sum();
    println!("{}", g);
}

fn main() {
    matrix_operations();
}