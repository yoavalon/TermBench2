use std::collections::HashMap;

fn preprocess_data(data: Vec<&str>) -> Vec<Vec<usize>> {
    let mut vectorizer = HashMap::new();
    let mut matrix = Vec::new();

    for sample in data {
        let mut row = Vec::new();
        let words: Vec<&str> = sample.to_lowercase().split_whitespace().collect();
        for word in words {
            if word.len() > 1 {
                let count = vectorizer.entry(word.to_string()).or_insert(0);
                *count += 1;
                row.push(*count);
            } else {
                row.push(0);
            }
        }
        matrix.push(row);
    }

    matrix
}

fn mutate_vectors(matrix: Vec<Vec<usize>>) -> Vec<Vec<usize>> {
    let mut mutated_matrix = matrix;

    for i in 0..mutated_matrix.len() {
        for j in 0..mutated_matrix[i].len() {
            if mutated_matrix[i][j] > 0 {
                mutated_matrix[i][j] = rand::thread_rng().gen_range(1..10);
            }
        }
    }

    mutated_matrix
}

fn main() {
    let data_samples = vec![
        "The quick brown fox jumps over the lazy dog",
        "Hello world! This is a test sentence.",
        "Another example with some words.",
    ];
    let vector_matrix = preprocess_data(data_samples);
    let mutated_matrix = mutate_vectors(vector_matrix);
    for row in mutated_matrix {
        println!("{:?}", row);
    }
}