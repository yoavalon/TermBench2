use sha2::{Sha256, Digest};

fn hash_string(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let result = hasher.finalize();
    format!("{:x}", result)
}

fn simulate_cipher(key: &str, data: &str) -> String {
    let mut cipher_output = String::new();
    for (i, c) in data.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = ((c as u8 + key_char as u8) % 256) as char;
        cipher_output.push(encrypted_char);
    }
    cipher_output
}

fn main() {
    loop {
        let key = "secretkey";
        let data = "sensitiveinfo";
        let hashed_data = hash_string(data);
        let encrypted_data = simulate_cipher(key, &hashed_data);
        println!("{}", encrypted_data);
    }
}