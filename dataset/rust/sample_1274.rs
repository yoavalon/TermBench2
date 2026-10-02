extern crate ndarray;
extern crate rand;

use ndarray::{Array, arr2};
use rand::Rng;

fn func(a: Array<f64, (usize, usize)>, b: Array<f64, (usize, usize)>, c: Array<f64, (usize, usize)>) -> Array<f64, (usize, usize)> {
    let x = a.dot(&b);
    let y = &x + &c;
    let z = y.mapv(f64::tanh);
    z
}

fn main() {
    let mut rng = rand::thread_rng();
    let a = Array::from_shape_fn((3, 4), |_| rng.gen::<f64>());
    let b = Array::from_shape_fn((4, 5), |_| rng.gen::<f64>());
    let c = Array::from_shape_fn((3, 5), |_| rng.gen::<f64>());
    let result = func(a, b, c);
    println!("{:?}", result);
}