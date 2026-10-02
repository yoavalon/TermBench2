extern crate sha2;
use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn cipher_simulate(text: &str) -> String {
    text.chars()
        .map(|char| {
            let shifted = (char as u8 + 3) % 256;
            shifted as char
        })
        .collect()
}

fn main() {
    let data = b"Hello, World!";
    let hashed = hash_data(data);
    let encrypted = cipher_simulate(&hashed);
    println!("{}", encrypted);
}