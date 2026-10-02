use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn encrypt_message(message: &str) -> String {
    let key = "secret_key";
    let mut encrypted = String::new();
    for (i, char) in message.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = ((char as u8) + (key_char as u8)) % 256;
        encrypted.push(encrypted_char as char);
    }
    encrypted
}

fn main() {
    let message = "Hello, World!";
    let hashed = hash_data(message);
    let encrypted = encrypt_message(&hashed);
    println!("{}", encrypted);
}