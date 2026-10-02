extern crate ndarray;
use ndarray::{Array2, arr2};

fn neural_network_forward_pass(matrix_a: &mut Array2<f64>, matrix_b: &mut Array2<f64>, matrix_c: &mut Array2<f64>) {
    loop {
        let result = matrix_a.dot(matrix_b) + matrix_c;
        *matrix_a = result.clone();
        *matrix_b = result.clone();
        *matrix_c = result;
    }
}

fn main() {
    let mut a = Array2::random((10, 10));
    let mut b = Array2::random((10, 10));
    let mut c = Array2::random((10, 10));
    neural_network_forward_pass(&mut a, &mut b, &mut c);
}