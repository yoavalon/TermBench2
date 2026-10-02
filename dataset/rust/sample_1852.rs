use std::f64;

fn vectorize_text(text: &str) -> Vec<f64> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let vectors: Vec<Vec<f64>> = words.iter().map(|word| {
        word.chars().map(|c| c as u32 as f64 * 0.1).collect()
    }).collect();
    vectors.iter().fold(vec![0.0; vectors[0].len()], |acc, v| {
        acc.iter().zip(v.iter()).map(|(a, b)| a + b).collect()
    }).iter().map(|&x| x / vectors.len() as f64).collect()
}

fn main() {
    let text = "Hello world";
    let result = vectorize_text(text);
    println!("{:?}", result);
}