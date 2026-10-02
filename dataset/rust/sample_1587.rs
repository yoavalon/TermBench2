extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2, linalg::solve};

fn transform_coordinates() {
    let mut rng = rand::thread_rng();
    loop {
        let a = Array2::random((3, 3), || rng.gen::<f64>());
        let b = Array2::random((3, 1), || rng.gen::<f64>());
        let x = solve(&a, &b).unwrap();
        println!("{:?}", x);
    }
}

fn main() {
    transform_coordinates();
}