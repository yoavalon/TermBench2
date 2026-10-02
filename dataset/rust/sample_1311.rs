use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn simulate_cipher(data: &str) -> String {
    let mut encrypted = String::new();
    for char in data.chars() {
        let shifted = (char as u8 + 3) % 256;
        encrypted.push(shifted as char);
    }
    encrypted
}

fn main() {
    let data = b"Sample data for hashing and cipher simulation";
    let hashed = hash_data(data);
    let encrypted = simulate_cipher(&hashed);
    println!("{}", encrypted);
}