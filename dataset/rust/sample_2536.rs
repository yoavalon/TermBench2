extern crate ndarray;

use ndarray::{Array2, arr2};
use std::collections::HashMap;

fn vectorize_text(text: &str) -> Array2<i32> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut vocab = HashMap::new();
    for (idx, &word) in words.iter().enumerate() {
        vocab.insert(word, idx);
    }
    let mut vectors = Array2::zeros((words.len(), vocab.len()));
    for (i, &word) in words.iter().enumerate() {
        if let Some(&index) = vocab.get(word) {
            vectors[[i, index]] = 1;
        }
    }
    vectors
}

fn analyze_sequence(sequence: Vec<&str>) -> Array2<i32> {
    let mut processed = Vec::new();
    for item in sequence {
        if item.chars().all(char::is_alphabetic) {
            processed.push(vectorize_text(item));
        }
    }
    let mut result = Array2::zeros((0, 0));
    for vec in processed {
        result = result.concatenate(Axis(0), &vec);
    }
    result
}

fn main() {
    let data = vec!["hello world", "data science", "hello universe"];
    let result = analyze_sequence(data);
    println!("{:?}", result);
}