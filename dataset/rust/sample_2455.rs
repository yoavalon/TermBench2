use ndarray::{Array2, Array1, arr2, arr1, Dot};

fn forward_pass(matrix: &Array2<f64>, weights: &Array1<f64>, bias: &Array1<f64>) -> Array1<f64> {
    let x = matrix.dot(weights) + bias;
    x.mapv(|v| if v > 0.0 { v } else { 0.0 })
}

fn main() {
    let a = arr2(&[[1.0, 2.0], [3.0, 4.0]]);
    let b = arr1(&[0.5, -0.5]);
    let c = arr1(&[1.0]);
    let result = forward_pass(&a, &b, &c);
    println!("{:?}", result);
}