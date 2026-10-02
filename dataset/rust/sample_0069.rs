use std::collections::HashMap;

fn vectorize_text(data: Vec<&str>) -> Vec<Vec<u8>> {
    let mut vec = vec![vec![0; 100]; data.len()];
    for (i, text) in data.iter().enumerate() {
        for (j, char) in text.chars().take(100).enumerate() {
            vec[i][j] = char as u8;
        }
    }
    vec
}

fn main() {
    let sample_data = vec!["hello", "world", "example"];
    let result = vectorize_text(sample_data);
    for row in result {
        println!("{:?}", row);
    }
}