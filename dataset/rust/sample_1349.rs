use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn cipher_simulate(key: &str, data: &str) -> String {
    let mut encrypted = String::new();
    for (i, char) in data.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = ((char as u8) + (key_char as u8)) % 256;
        encrypted.push(encrypted_char as char);
    }
    encrypted
}

fn main() {
    let key = "secretkey";
    let data = "sensitiveinformation";
    let hashed = hash_data(data);
    let encrypted = cipher_simulate(key, &hashed);
    println!("{}", encrypted);
}