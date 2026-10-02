use sha2::{Sha256, Digest};

fn generate_hash(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn simulate_cipher(hash_val: &str) -> String {
    let key = b"secret";
    let mut cipher_text = Vec::new();
    for i in 0..hash_val.len() {
        let byte = u8::from_str_radix(&hash_val[i..i + 2], 16).unwrap() ^ key[i % key.len()];
        cipher_text.push(byte);
    }
    format!("{:x}", cipher_text)
}

fn main() {
    let data = "secure_message";
    let hash_val = generate_hash(data);
    let cipher_text = simulate_cipher(&hash_val);
    println!("{}", cipher_text);
}