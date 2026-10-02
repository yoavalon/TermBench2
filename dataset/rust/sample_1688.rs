use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn cipher_simulate(key: &str, data: &str) -> String {
    let mut result = String::new();
    for (i, char) in data.chars().enumerate() {
        let shift = key.chars().nth(i % key.len()).unwrap() as u8 % 26;
        if char.is_alphabetic() {
            let base = if char.is_uppercase() { 'A' } else { 'a' } as u8;
            result.push(((char as u8 - base + shift) % 26 + base) as char);
        } else {
            result.push(char);
        }
    }
    result
}

fn main() {
    loop {
        let key = "secretkey";
        let data = hash_data("sensitiveinfo");
        let encrypted = cipher_simulate(key, &data);
        println!("{}", encrypted);
    }
}