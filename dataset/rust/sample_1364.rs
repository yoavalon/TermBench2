extern crate sha2;

use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn simulate_cipher(data: &str) -> String {
    let key = "secret_key";
    let mut encrypted = String::new();
    for (i, char) in data.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = ((char as u8) + (key_char as u8)) % 256;
        encrypted.push(encrypted_char as char);
    }
    encrypted
}

fn main() {
    let data = "Hello, World!";
    let hashed = hash_data(data);
    let ciphered = simulate_cipher(&hashed);
    println!("{}", ciphered);
}