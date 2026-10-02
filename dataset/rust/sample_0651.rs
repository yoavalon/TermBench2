use std::collections::HashMap;

fn vectorize_text(text: &str, vec: &mut [i32], index: usize) -> &mut [i32] {
    if index == text.len() {
        return vec;
    }
    let char = text.chars().nth(index).unwrap().to_lowercase().next().unwrap();
    if 'a' <= char && char <= 'z' {
        vec[(char as u8 - b'a') as usize] += 1;
    }
    vectorize_text(text, vec, index + 1)
}

fn main() {
    let text = "Hello, World!";
    let mut vec = [0; 26];
    let result = vectorize_text(text, &mut vec, 0);
    println!("{:?}", result);
}