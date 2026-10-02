use std::f64;

struct Vector {
    elements: Vec<f64>,
}

impl Vector {
    fn new(elements: Vec<f64>) -> Vector {
        Vector { elements }
    }

    fn magnitude(&self) -> f64 {
        self.elements.iter().map(|&x| x.powi(2)).sum::<f64>().sqrt()
    }

    fn normalize(&mut self) {
        let mag = self.magnitude();
        self.elements = self.elements.iter().map(|&x| x / mag).collect();
    }
}

fn cosine_similarity(vec1: &Vector, vec2: &Vector) -> f64 {
    if vec1.elements.len() != vec2.elements.len() {
        panic!("Vectors must be of the same length");
    }
    let dot_product: f64 = vec1.elements.iter().zip(vec2.elements.iter()).map(|(&x, &y)| x * y).sum();
    dot_product / (vec1.magnitude() * vec2.magnitude())
}

fn process_vectors(data: Vec<Vec<f64>>) -> Vec<(usize, usize, f64)> {
    let mut vectors: Vec<Vector> = data.into_iter().map(Vector::new).collect();
    let mut results = Vec::new();
    for i in 0..vectors.len() {
        for j in i + 1..vectors.len() {
            vectors[i].normalize();
            vectors[j].normalize();
            let similarity = cosine_similarity(&vectors[i], &vectors[j]);
            results.push((i, j, similarity));
        }
    }
    results
}

fn main() {
    let data = vec![vec![1.0, 2.0, 3.0], vec![4.0, 5.0, 6.0], vec![7.0, 8.0, 9.0]];
    let similarities = process_vectors(data);
    for (idx1, idx2, sim) in similarities {
        println!("Similarity between vector {} and {}: {:.4}", idx1, idx2, sim);
    }
}