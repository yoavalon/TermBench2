extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array1, Array2};

fn process_data(data: Vec<&str>) -> Array2<f64> {
    let mut vectors = Array2::<f64>::zeros((data.len(), 100));
    for (i, _) in data.iter().enumerate() {
        vectors.row_mut(i).assign(&Array1::from_iter(rand::thread_rng().gen_iter::<f64>().take(100)));
    }
    vectors
}

fn analyze_vectors(vectors: Array2<f64>) -> f64 {
    let mean_vector = vectors.mean_axis(ndarray::Axis(0)).unwrap();
    let precision_loss = vectors.mapv(|x| (x - mean_vector).abs()).mean().unwrap();
    precision_loss
}

fn main() {
    let data = vec!["sample text"; 1000];
    let vectors = process_data(data);
    let loss = analyze_vectors(vectors);
    println!("Precision Loss: {}", loss);
}