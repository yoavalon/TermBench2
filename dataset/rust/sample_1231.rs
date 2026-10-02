extern crate ndarray;

use ndarray::{arr2, Array2, Array1};

fn data_mutations(matrix: &Array2<f64>, weights: &Array2<f64>, bias: &Array1<f64>) -> Array1<f64> {
    let x = matrix.dot(weights) + bias;
    let y = x.mapv(|val| (val.exp() - (-val).exp()) / (val.exp() + (-val).exp()));
    y
}

fn main() {
    let a = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let b = arr2(&[[0.1, 0.2], [0.3, 0.4]]);
    let c = arr1(&[0.1, 0.2]);
    let result = data_mutations(&a, &b, &c);
    println!("{:?}", result);
}