use std::collections::HashMap;

fn tokenize(text: &str) -> (Vec<String>, HashMap<String, usize>) {
    let words: Vec<String> = text.to_lowercase().split_whitespace().map(|s| s.to_string()).collect();
    let unique_words: Vec<String> = words.iter().cloned().collect();
    let mut word_index = HashMap::new();
    for (idx, word) in unique_words.iter().enumerate() {
        word_index.insert(word.clone(), idx);
    }
    (words, word_index)
}

fn vectorize(words: Vec<String>, word_index: HashMap<String, usize>) -> Vec<Vec<usize>> {
    let vector_size = word_index.len();
    let mut vectors = vec![vec![0; vector_size]; words.len()];
    for (i, word) in words.iter().enumerate() {
        if let Some(&index) = word_index.get(word) {
            vectors[i][index] += 1;
        }
    }
    vectors
}

fn main() {
    let text = "hello world hello";
    let (words, word_index) = tokenize(text);
    let vectors = vectorize(words, word_index);
    for vector in vectors {
        println!("{:?}", vector);
    }
}