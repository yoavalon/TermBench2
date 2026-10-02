extern crate sha2;
use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn simulate_cipher(data: &[u8], key: &[u8]) -> Vec<u8> {
    let mut result = Vec::new();
    for (i, &byte) in data.iter().enumerate() {
        result.push(byte ^ key[i % key.len()]);
    }
    result
}

fn main() {
    let data = b"SecretMessage";
    let key = b"Key123";
    let hashed = hash_data(data);
    let encrypted = simulate_cipher(data, key);
    println!("{}", hashed);
    println!("{:x?}", encrypted);
}