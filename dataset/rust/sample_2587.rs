extern crate ndarray;

use ndarray::Array1;

fn tokenize(text: &str) -> Vec<String> {
    text.to_lowercase()
        .split_whitespace()
        .map(|s| s.to_string())
        .collect()
}

fn vectorize(tokens: Vec<String>, vocab: &std::collections::HashMap<String, usize>) -> Array1<i32> {
    let mut vector = Array1::zeros(vocab.len());
    for token in tokens {
        if let Some(&index) = vocab.get(&token) {
            vector[index] += 1;
        }
    }
    vector
}

fn process_text(text: &str) -> Array1<i32> {
    let vocab = vec![
        ("hello".to_string(), 0),
        ("world".to_string(), 1),
        ("python".to_string(), 2),
    ]
    .into_iter()
    .collect::<std::collections::HashMap<String, usize>>();
    let tokens = tokenize(text);
    vectorize(tokens, &vocab)
}

fn main() {
    let text = "Hello world, hello Python!";
    let result = process_text(text);
    println!("{:?}", result);
}