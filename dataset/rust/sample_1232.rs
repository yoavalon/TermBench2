extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2};

fn data_mutations(x: &Array2<f64>) -> Array2<f64> {
    let mut rng = rand::thread_rng();
    let w = Array2::from_shape_fn((x.ncols(), 10), |_| rng.gen::<f64>());
    let b = Array2::from_shape_fn((10,), |_| rng.gen::<f64>());
    let z = x.dot(&w) + &b;
    let a = z.mapv(|v| v.max(0.0));
    let w2 = Array2::from_shape_fn((10, 1), |_| rng.gen::<f64>());
    let b2 = Array2::from_shape_fn((1,), |_| rng.gen::<f64>());
    let z2 = a.dot(&w2) + &b2;
    z2
}

fn main() {
    let mut rng = rand::thread_rng();
    let x = Array2::from_shape_fn((5, 10), |_| rng.gen::<f64>());
    let result = data_mutations(&x);
    println!("{:?}", result);
}