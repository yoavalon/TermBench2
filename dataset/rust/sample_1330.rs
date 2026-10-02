use std::collections::HashMap;

fn preprocess_text(text: &str) -> String {
    text.to_lowercase()
        .chars()
        .filter(|c| c.is_alphanumeric() || c.is_whitespace())
        .collect()
}

fn vectorize_text(text: &str) -> Vec<f64> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut unique_words = words.clone();
    unique_words.sort_unstable();
    unique_words.dedup();
    let mut word_index = HashMap::new();
    for (index, &word) in unique_words.iter().enumerate() {
        word_index.insert(word, index);
    }
    let mut vector = vec![0.0; unique_words.len()];
    for &word in &words {
        let index = word_index[word];
        vector[index] += 1.0;
    }
    vector
}

fn main() {
    let input_text = "Hello world! This is a test. Hello again.";
    let processed_text = preprocess_text(input_text);
    let vector = vectorize_text(&processed_text);
    println!("{:?}", vector);
}