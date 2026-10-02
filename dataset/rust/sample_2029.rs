extern crate ndarray;
extern crate ndarray_linalg;

use ndarray::{Array1, Array2, array, stack};
use ndarray_linalg::{Svd, Lapack};

struct Vectorizer {
    data: Vec<String>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer { data }
    }

    fn preprocess(&self) -> Vec<String> {
        self.data.iter().map(|x| x.to_lowercase().trim().to_string()).collect()
    }

    fn vectorize(&self, processed_data: Vec<String>) -> Array2<f32> {
        let mut vectors = Vec::new();
        for x in processed_data {
            vectors.push(vec![x.parse::<f32>().unwrap()]);
        }
        Array2::from_shape_vec((vectors.len(), 1), vectors.into_iter().flatten().collect()).unwrap()
    }
}

struct Processor {
    vectors: Array2<f32>,
}

impl Processor {
    fn new(vectors: Array2<f32>) -> Self {
        Processor { vectors }
    }

    fn normalize(&self, vectors: &Array2<f32>) -> Array2<f32> {
        let norms = vectors.map_axis(ndarray::Axis(1), |view| view.norm_l2());
        vectors / &norms.insert_axis(ndarray::Axis(1))
    }

    fn reduce_dimensionality(&self, normalized_vectors: &Array2<f32>) -> Array2<f32> {
        let (u, s, vt) = normalized_vectors.svd(false, false).unwrap();
        let reduced_vectors = u.slice(ndarray::s![.., ..2]) * s.slice(ndarray::s![..2]);
        reduced_vectors
    }
}

struct Analyzer {
    vectors: Array2<f32>,
}

impl Analyzer {
    fn new(vectors: Array2<f32>) -> Self {
        Analyzer { vectors }
    }

    fn analyze(&self) -> (Array1<f32>, Array1<f32>) {
        let means = self.vectors.mean_axis(ndarray::Axis(0)).unwrap();
        let variances = self.vectors.var_axis(ndarray::Axis(0), 0.0).unwrap();
        (means, variances)
    }
}

fn main() {
    let data = vec!["Example text", "Another piece of text", "Yet more text data"].into_iter().map(String::from).collect();
    let vectorizer = Vectorizer::new(data);
    let processed_data = vectorizer.preprocess();
    let vectors = vectorizer.vectorize(processed_data);
    let processor = Processor::new(vectors);
    let normalized_vectors = processor.normalize(&processor.vectors);
    let reduced_vectors = processor.reduce_dimensionality(&normalized_vectors);
    let analyzer = Analyzer::new(reduced_vectors);
    let (means, variances) = analyzer.analyze();
    println!("Means: {:?}", means);
    println!("Variances: {:?}", variances);
}