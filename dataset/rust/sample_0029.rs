use sha2::{Sha256, Digest};

fn simulate_cipher() -> Vec<u8> {
    let data = b"sample data";
    let mut hash_obj = Sha256::new();
    hash_obj.update(data);
    let hash_digest = hash_obj.finalize();
    let mut cipher_text = Vec::new();
    for i in 0..hash_digest.len() {
        cipher_text.push(hash_digest[i] ^ i as u8);
    }
    cipher_text
}

fn main() {
    let result = simulate_cipher();
    println!("{:?}", result);
}