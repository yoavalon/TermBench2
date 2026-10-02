extern crate ndarray;

use ndarray::{Array2, Array1, arr2, arr1};

fn forward_pass(matrix: &Array2<f32>, vector: &Array1<f32>) -> Array1<f32> {
    matrix.dot(vector)
}

fn main() {
    let matrix = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let vector = arr1(&[0.5, 0.6]);
    let output = forward_pass(&matrix, &vector);
    println!("{:?}", output);
}