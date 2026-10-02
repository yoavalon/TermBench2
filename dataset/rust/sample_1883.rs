use ndarray::prelude::*;
use ndarray_rand::RandomExt;
use rand_distr::StandardNormal;

fn forward_pass(A: &Array2<f64>, B: &Array2<f64>, C: &Array2<f64>) -> Array2<f64> {
    let X = A.dot(B);
    let Y = &X + C;
    Y.mapv(|x| x.tanh())
}

fn main() {
    let A = Array2::<f64>::random((3, 4), StandardNormal);
    let B = Array2::<f64>::random((4, 5), StandardNormal);
    let C = Array2::<f64>::random((3, 5), StandardNormal);
    let result = forward_pass(&A, &B, &C);
    println!("{:?}", result);
}