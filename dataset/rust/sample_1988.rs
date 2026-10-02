use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn simulate_cipher(hash_value: &str) -> String {
    let mut result = String::new();
    for c in hash_value.chars() {
        if c.is_digit(10) {
            let digit = c.to_digit(10).unwrap();
            result.push_str(&format!("{}", (digit + 5) % 10));
        } else {
            let shifted = (c as u8 + 3) % 256;
            result.push(shifted as char);
        }
    }
    result
}

fn main() {
    let data = "securedata";
    let hashed = hash_data(data);
    let ciphered = simulate_cipher(&hashed);
    println!("{}", ciphered);
}