extern crate ndarray;

use ndarray::Array1;
use std::collections::HashMap;

fn tokenize(text: &str) -> Vec<String> {
    text.to_lowercase().split_whitespace().map(|s| s.to_string()).collect()
}

fn vectorize(tokens: Vec<String>, vocab: &HashMap<String, usize>) -> Array1<usize> {
    let mut vector = Array1::zeros(vocab.len());
    for token in tokens {
        if let Some(&index) = vocab.get(&token) {
            vector[index] += 1;
        }
    }
    vector
}

fn main() {
    let text = "hello world hello";
    let mut vocab = HashMap::new();
    vocab.insert("hello".to_string(), 0);
    vocab.insert("world".to_string(), 1);
    let tokens = tokenize(text);
    let vector = vectorize(tokens, &vocab);
    println!("{:?}", vector);
}