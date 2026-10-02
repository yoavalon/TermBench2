use ndarray::{Array2, Array1};
use ndarray_linalg::norm::Norm;

fn process_text(data: Vec<&str>) -> Array2<f64> {
    let vectors: Array2<f64> = data
        .iter()
        .map(|t| t.chars().map(|c| c as f64).collect::<Vec<f64>>())
        .collect();
    let norms: Array1<f64> = vectors.map_axis(ndarray::Axis(1), |row| row.norm_l2());
    let normalized_vectors = vectors / norms.insert_axis(ndarray::Axis(1));
    normalized_vectors
}

fn main() {
    let data = vec!["hello", "world"];
    let result = process_text(data);
    println!("{:?}", result);
}