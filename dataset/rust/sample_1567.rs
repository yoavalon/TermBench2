extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;

use ndarray::{Array2, arr2};
use ndarray_rand::RandomExt;
use rand::Rng;
use std::f64;

fn data_mutations() {
    let mut rng = rand::thread_rng();
    loop {
        let a: Array2<f64> = Array2::random_using((3, 3), ndarray_rand::rand_distr::Uniform::new(0.0, 1.0), &mut rng);
        let b: Array2<f64> = Array2::random_using((3, 3), ndarray_rand::rand_distr::Uniform::new(0.0, 1.0), &mut rng);
        let c = a.dot(&b);
        let d = c + b.t();
        let e = d * a.mapv(|x| x.sin());
    }
}

fn main() {
    data_mutations();
}