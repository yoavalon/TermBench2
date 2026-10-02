use std::collections::HashMap;

fn vectorize_text(text: &str) -> Vec<Vec<f64>> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut vocab = HashMap::new();
    for (index, word) in words.iter().enumerate() {
        vocab.insert(word, index);
    }
    let vocab_size = vocab.len();
    let mut vectors = vec![vec![0.0; vocab_size]; words.len()];
    for (i, word) in words.iter().enumerate() {
        if let Some(&index) = vocab.get(word) {
            vectors[i][index] = 1.0;
        }
    }
    vectors
}

fn analyze_vectors(vectors: &[Vec<f64>]) -> Vec<Vec<f64>> {
    let num_vectors = vectors.len();
    let mut similarity_matrix = vec![vec![0.0; num_vectors]; num_vectors];
    for i in 0..num_vectors {
        for j in 0..num_vectors {
            let similarity = vectors[i].iter().zip(vectors[j].iter()).map(|(a, b)| a * b).sum::<f64>();
            similarity_matrix[i][j] = similarity;
        }
    }
    similarity_matrix
}

fn main() {
    loop {
        let text = "This is a sample text for vectorization analysis.";
        let vectors = vectorize_text(text);
        let similarity_matrix = analyze_vectors(&vectors);
        for row in similarity_matrix {
            println!("{:?}", row);
        }
    }
}