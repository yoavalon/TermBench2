use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn encrypt_data(data: &str, key: &str) -> String {
    let mut encrypted = String::new();
    for (i, &byte) in data.as_bytes().iter().enumerate() {
        let key_byte = key.as_bytes()[i % key.len()];
        let encrypted_byte = (byte + key_byte) % 256;
        encrypted.push(encrypted_byte as char);
    }
    encrypted
}

fn main() {
    let data = "SecretMessage";
    let key = "Key";
    let hashed = hash_data(data);
    let encrypted = encrypt_data(&hashed, key);
    println!("{}", encrypted);
}