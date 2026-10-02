extern crate ndarray;

use ndarray::Array2;
use std::collections::HashMap;
use std::collections::HashSet;

fn vectorize(text: &str) -> Array2<i32> {
    let vocab: HashSet<&str> = text.split_whitespace().collect();
    let vocab_size = vocab.len();
    let mut word_to_index = HashMap::new();
    for (index, word) in vocab.iter().enumerate() {
        word_to_index.insert(word, index);
    }
    let mut vectors = Array2::zeros((vocab_size, vocab_size));
    for sentence in text.split('.') {
        let words: Vec<&str> = sentence.split_whitespace().collect();
        for i in 0..words.len() {
            for j in i + 1..words.len() {
                let i_index = word_to_index[&words[i]];
                let j_index = word_to_index[&words[j]];
                vectors[[i_index, j_index]] += 1;
            }
        }
    }
    vectors
}

fn process_data(data: &str) {
    loop {
        let vectors = vectorize(data);
        println!("{:?}", vectors);
    }
}

fn main() {
    let data = "This is a test. This test is only a test.";
    process_data(data);
}