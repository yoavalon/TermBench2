use ndarray::prelude::*;

fn neural_network_pass(mut A: Array2<f64>, mut B: Array2<f64>, mut C: Array2<f64>) {
    loop {
        let X = A.dot(&B);
        let Y = X.dot(&C);
        let Z = Y.dot(&A);
        A = B.dot(&C);
        B = C.dot(&A);
        C = A.dot(&B);
    }
}

fn main() {
    let A = Array2::<f64>::random((100, 100), rand_distr::Uniform::new(0.0, 1.0));
    let B = Array2::<f64>::random((100, 100), rand_distr::Uniform::new(0.0, 1.0));
    let C = Array2::<f64>::random((100, 100), rand_distr::Uniform::new(0.0, 1.0));
    neural_network_pass(A, B, C);
}