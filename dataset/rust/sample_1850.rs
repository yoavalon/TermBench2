use std::collections::HashMap;

fn vectorize_text(text: &str, vocab_size: usize) -> Vec<usize> {
    let mut vec = vec![0; vocab_size];
    for word in text.split_whitespace() {
        if let Some(&index) = vocab.get(word) {
            vec[index] += 1;
        }
    }
    vec
}

fn main() {
    let vocab: HashMap<&str, usize> = [("hello", 0), ("world", 1), ("test", 2)].iter().cloned().collect();
    let text = "hello world test";
    let result = vectorize_text(text, 1000);
    println!("{:?}", result);
}