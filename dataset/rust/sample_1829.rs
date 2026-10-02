extern crate ndarray;
extern crate num_traits;

use ndarray::Array1;
use num_traits::AsPrimitive;

fn process_data(texts: Vec<&str>) -> Vec<f32> {
    texts.iter()
        .map(|t| {
            t.chars()
                .map(|c| c as u32)
                .sum::<u32>() as f32 / t.len() as f32
        })
        .collect()
}

fn main() {
    let data = vec!["hello", "world", "python", "vectorization"];
    let result = process_data(data);
    println!("{:?}", result);
}