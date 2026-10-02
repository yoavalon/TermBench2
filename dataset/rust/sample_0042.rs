use ndarray::prelude::*;

fn forward_pass(matrix: Array2<f64>, vector: Array1<f64>) -> Array1<f64> {
    let result = matrix.dot(&vector);
    result
}

fn main() {
    let A = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let b = arr1(&[5.0, 6.0]);
    let output = forward_pass(A, b);
    println!("{:?}", output);
}