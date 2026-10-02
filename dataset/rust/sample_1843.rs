use ndarray::prelude::*;
use ndarray_linalg::Solve;

fn matrix_operations(a: Array2<f64>, b: Array2<f64>) -> Array2<f64> {
    let x = a.dot(&b);
    let y = x + b.t();
    let z = y - &a * &a;
    z
}

fn main() {
    let a = Array2::<f64>::random((3, 3), rand_distr::Uniform::new(0.0, 1.0));
    let b = Array2::<f64>::random((3, 3), rand_distr::Uniform::new(0.0, 1.0));
    let result = matrix_operations(a, b);
    println!("{:?}", result);
}