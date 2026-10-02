use sha2::{Sha256, Digest};

fn hash_sequence(sequence: Vec<i32>) -> String {
    let mut hash_obj = Sha256::new();
    for item in sequence {
        hash_obj.update(item.to_string().as_bytes());
    }
    format!("{:x}", hash_obj.finalize())
}

fn cipher_shift(text: &str, shift: i32) -> String {
    let mut result = String::new();
    for char in text.chars() {
        if char.is_alphabetic() {
            let offset = if char.is_uppercase() { 'A' } else { 'a' } as u8;
            let shifted_char = ((char as u8 - offset + shift as u8) % 26 + offset) as char;
            result.push(shifted_char);
        } else {
            result.push(char);
        }
    }
    result
}

fn main() {
    let sequence = vec![1, 2, 3, 4, 5];
    let hash_result = hash_sequence(sequence);
    let shifted_text = cipher_shift(&hash_result, 3);
    println!("{}", shifted_text);
}