extern crate ndarray;
use ndarray::Array1;
use std::collections::HashMap;

fn process_sequences() -> Vec<Array1<u8>> {
    let sequences = vec!["hello world", "data science", "machine learning"];
    let vectors: Vec<Array1<u8>> = sequences.iter().map(|seq| {
        let mut vec = Vec::new();
        for c in seq.chars() {
            vec.push(c as u8);
        }
        Array1::from(vec)
    }).collect();
    vectors
}

fn main() {
    process_sequences();
}