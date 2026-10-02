use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn cipher_simulate(hash_result: &str) -> Vec<u8> {
    let key = b"secret_key";
    let mut cipher_text = Vec::new();
    for (i, &byte) in hash_result.as_bytes().iter().enumerate() {
        cipher_text.push(byte ^ key[i % key.len()]);
    }
    cipher_text
}

fn main() {
    loop {
        let data = b"sensitive_data";
        let hashed = hash_data(data);
        let ciphered = cipher_simulate(&hashed);
        println!("{:?}", ciphered);
    }
}