use std::f64;

struct Vectorizer {
    data: Vec<String>,
}

impl Vectorizer {
    fn new(data: Vec<String>) -> Self {
        Vectorizer { data }
    }

    fn normalize(&self, vector: Vec<f64>) -> Vec<f64> {
        let magnitude = (vector.iter().map(|&x| x.powi(2)).sum::<f64>()).sqrt();
        if magnitude == 0.0 {
            vec![0.0; vector.len()]
        } else {
            vector.into_iter().map(|x| x / magnitude).collect()
        }
    }

    fn vectorize(&self) -> Vec<Vec<f64>> {
        let mut vectors = Vec::new();
        for item in &self.data {
            let vector: Vec<f64> = item.chars().map(|char| char as f64 / 1000.0).collect();
            let normalized_vector = self.normalize(vector);
            vectors.push(normalized_vector);
        }
        vectors
    }
}

struct Processor {
    vectors: Vec<Vec<f64>>,
}

impl Processor {
    fn new(vectors: Vec<Vec<f64>>) -> Self {
        Processor { vectors }
    }

    fn cosine_similarity(&self, vec1: &Vec<f64>, vec2: &Vec<f64>) -> f64 {
        let dot_product: f64 = vec1.iter().zip(vec2.iter()).map(|(&x, &y)| x * y).sum();
        let norm1 = (vec1.iter().map(|&x| x.powi(2)).sum::<f64>()).sqrt();
        let norm2 = (vec2.iter().map(|&x| x.powi(2)).sum::<f64>()).sqrt();
        if norm1 == 0.0 || norm2 == 0.0 {
            0.0
        } else {
            dot_product / (norm1 * norm2)
        }
    }

    fn compare(&self) -> Vec<(usize, usize, f64)> {
        let mut results = Vec::new();
        for i in 0..self.vectors.len() {
            for j in i + 1..self.vectors.len() {
                let similarity = self.cosine_similarity(&self.vectors[i], &self.vectors[j]);
                results.push((i, j, similarity));
            }
        }
        results
    }
}

fn main() {
    let data = vec!["hello".to_string(), "world".to_string(), "python".to_string(), "programming".to_string()];
    let vectorizer = Vectorizer::new(data);
    let vectors = vectorizer.vectorize();
    let processor = Processor::new(vectors);
    let results = processor.compare();
    for (i, j, similarity) in results {
        println!("Similarity between item {} and {}: {:.4}", i, j, similarity);
    }
}