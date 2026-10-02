extern crate ndarray;
use ndarray::{Array1, Array2, arr2};

fn process_text(data: Vec<&str>) -> Array2<f64> {
    let mut vectors = Vec::new();
    for d in data {
        let vector: Array1<f64> = d.split_whitespace()
                                   .map(|x| x.parse().unwrap())
                                   .collect();
        vectors.push(vector);
    }
    Array2::from_shape_vec((vectors.len(), vectors[0].len()), vectors.into_iter().flatten().collect()).unwrap()
}

fn compute_similarity(vectors: Array2<f64>) -> Array2<f64> {
    let dot_products = vectors.dot(&vectors.t());
    let norms = vectors.map_axis(ndarray::Axis(1), |view| view.norm_l2());
    let norms_matrix = norms.view().dot(&norms.view().t());
    dot_products / norms_matrix
}

fn main() {
    let data = vec!["0.1 0.2 0.3", "0.4 0.5 0.6", "0.7 0.8 0.9"];
    let vectors = process_text(data);
    let similarities = compute_similarity(vectors);
    println!("{:?}", similarities);
}