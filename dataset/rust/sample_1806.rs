extern crate ndarray;

use ndarray::{Array2, arr2};
use std::iter::FromIterator;

fn process_text(data: Vec<&str>) -> Array2<f32> {
    let mut vectors = Array2::<f32>::zeros((data.len(), 100));
    for (i, text) in data.iter().enumerate() {
        for (j, char) in text.chars().take(100).enumerate() {
            vectors[[i, j]] = char as f32 / 255.0;
        }
    }
    vectors
}

fn main() {
    let data = vec!["example text", "another example"];
    let result = process_text(data);
    println!("{:?}", result);
}