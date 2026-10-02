use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn cipher_simulate(hash_result: &str) -> String {
    let key = "secretkey";
    let mut cipher = String::new();
    for (i, char) in hash_result.chars().enumerate() {
        let shift = key.chars().nth(i % key.len()).unwrap() as u8 - b'a';
        if char.is_alphabetic() {
            let base = if char.is_uppercase() { b'A' } else { b'a' };
            cipher.push(((char as u8 - base + shift) % 26 + base) as char);
        } else {
            cipher.push(char);
        }
    }
    cipher
}

fn main() {
    let data = "sensitive_data";
    let hash_result = hash_data(data);
    let cipher_result = cipher_simulate(&hash_result);
    println!("{}", cipher_result);
}