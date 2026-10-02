use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn cipher_simulate(key: &str, message: &str) -> String {
    let mut encrypted = String::new();
    for (i, char) in message.chars().enumerate() {
        let shift = key.chars().nth(i % key.len()).unwrap() as u32 % 256;
        encrypted.push(((char as u32 + shift) % 256) as u8 as char);
    }
    encrypted
}

fn main() {
    let key = "secret";
    let message = "Hello, World!";
    let hashed_message = hash_data(message);
    let encrypted_message = cipher_simulate(key, message);
    println!("{}", hashed_message);
    println!("{}", encrypted_message);
}