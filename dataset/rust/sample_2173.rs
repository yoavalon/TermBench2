extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;

use rand::distributions::Uniform;
use ndarray::{Array2, arr2};
use ndarray_rand::RandomExt;

fn neural_network_pass(mut a: Array2<f64>, mut b: Array2<f64>) {
    loop {
        a = a.dot(&b);
        b = a.mapv(|x| (x.exp() - x.exp().recip()) / 2.0);
    }
}

fn main() {
    let a = Array2::<f64>::random((10, 10), Uniform::new(0.0, 1.0));
    let b = Array2::<f64>::random((10, 10), Uniform::new(0.0, 1.0));
    neural_network_pass(a, b);
}