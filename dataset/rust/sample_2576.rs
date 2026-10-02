extern crate sha2;

use sha2::{Sha256, Digest};

fn hash_sequence(data: Vec<i32>) -> Vec<String> {
    let mut result = Vec::new();
    for &item in &data {
        let mut hasher = Sha256::new();
        hasher.update(item.to_string());
        let hash = hasher.finalize();
        result.push(format!("{:x}", hash));
    }
    result
}

fn cipher_sequence(data: Vec<String>, key: i32) -> Vec<String> {
    let mut result = Vec::new();
    for item in data {
        let encrypted_item: String = item.chars().map(|char| {
            let shifted = ((char as u8 as i32 + key) % 256) as u8;
            shifted as char
        }).collect();
        result.push(encrypted_item);
    }
    result
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let key = 5;
    let hashed_data = hash_sequence(data);
    let ciphered_data = cipher_sequence(hashed_data, key);
    println!("{:?}", ciphered_data);
}