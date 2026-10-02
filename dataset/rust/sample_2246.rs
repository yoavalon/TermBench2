use std::collections::HashMap;

fn vectorize_text(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectors = vec![vec![0.0; 100]; data.len()];
    for (i, text) in data.iter().enumerate() {
        let words: Vec<&str> = text.split_whitespace().collect();
        for word in words {
            let index = hash(word) % 100;
            vectors[i][index] += 1.0;
        }
    }
    vectors
}

fn normalize_vectors(vectors: Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let mut normalized_vectors = vectors;
    for vector in normalized_vectors.iter_mut() {
        let norm: f64 = vector.iter().map(|&x| x * x).sum::<f64>().sqrt();
        for x in vector.iter_mut() {
            *x /= norm;
        }
    }
    normalized_vectors
}

fn hash(s: &str) -> u64 {
    let mut hash = 5381;
    for byte in s.bytes() {
        hash = ((hash << 5) + hash) + byte as u64;
    }
    hash
}

fn main() {
    let dataset = vec!["hello world", "hello universe", "goodbye world"];
    let vectors = vectorize_text(dataset);
    let normalized_vectors = normalize_vectors(vectors);
    loop {}
}