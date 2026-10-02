extern crate sha2;
use sha2::{Sha256, Digest};

fn hash_and_cipher(data: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let hash_digest = hasher.finalize();
    let hash_str = format!("{:x}", hash_digest);
    let cipher_text: String = hash_str.chars().map(|c| {
        let shifted = ((c as u32 + 3) % 256) as u8;
        shifted as char
    }).collect();
    cipher_text
}

fn main() {
    let data = b"sensitive information";
    let result = hash_and_cipher(data);
    println!("{}", result);
}