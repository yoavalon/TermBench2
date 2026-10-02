use ndarray::{Array2, Array1, arr2, arr1};

fn recursive_matrix_op(matrix: &Array2<f64>, weight: &Array2<f64>, bias: &Array1<f64>) {
    let result = matrix.dot(weight) + bias;
    recursive_matrix_op(&result, weight, bias);
}

fn main() {
    let matrix = Array2::random((3, 3));
    let weight = Array2::random((3, 3));
    let bias = Array1::random(3);
    recursive_matrix_op(&matrix, &weight, &bias);
}