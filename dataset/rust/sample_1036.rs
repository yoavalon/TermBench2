extern crate regex;
extern crate ndarray;
extern crate itertools;

use regex::Regex;
use ndarray::Array1;
use std::collections::HashMap;

fn tokenize_text(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text.to_lowercase().as_str())
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn vectorize(word_list: &Vec<String>) -> Array1<i32> {
    let mut word_counts = HashMap::new();
    for word in word_list {
        *word_counts.entry(word.clone()).or_insert(0) += 1;
    }
    let vocabulary: Vec<&String> = word_counts.keys().cloned().collect();
    let mut vector = Array1::zeros(vocabulary.len());
    for word in word_list {
        if let Some(&index) = vocabulary.iter().position(|&x| x == word) {
            vector[index] += 1;
        }
    }
    vector
}

fn recursive_vectorize(text: &str) {
    let vector = vectorize(&tokenize_text(text));
    recursive_vectorize(text);
}

fn main() {
    let sample_text = "Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.";
    recursive_vectorize(sample_text);
}