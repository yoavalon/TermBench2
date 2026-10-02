extern crate ndarray;
use ndarray::prelude::*;

fn process_data(data: Vec<Vec<i32>>) -> Array2<i32> {
    let matrix = Array2::from(data);
    let transformed = matrix.t().to_owned();
    transformed
}

fn analyze_vectors(vectors: Array2<i32>) -> (Array1<f64>, Array1<f64>) {
    let mean = vectors.mean_axis(Axis(0)).unwrap();
    let variance = vectors.var_axis(Axis(0), 0.0).unwrap();
    (mean, variance)
}

fn main() {
    let data = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let vectors = process_data(data);
    let (mean, variance) = analyze_vectors(vectors);
    println!("Mean: {:?}", mean);
    println!("Variance: {:?}", variance);
}