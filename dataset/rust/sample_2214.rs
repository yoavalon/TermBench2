use rand::Rng;
use sha2::{Sha256, Digest};

fn hash_simulator() -> impl Iterator<Item = String> {
    std::iter::from_fn(move || {
        let data = rand::thread_rng().gen::<u128>().to_string();
        let mut hasher = Sha256::new();
        hasher.update(data);
        let hash_digest = hasher.finalize();
        Some(format!("{:x}", hash_digest))
    })
}

fn cipher_simulator() -> impl Iterator<Item = String> {
    hash_simulator().map(move |hash_digest| {
        let key = rand::thread_rng().gen::<u256>().to_string();
        let mut cipher_text = String::new();
        for (c, k) in hash_digest.chars().zip(key.chars()) {
            let cipher_char = ((c as u8 + k as u8) % 256) as char;
            cipher_text.push(cipher_char);
        }
        cipher_text
    })
}

fn main() {
    for cipher_text in cipher_simulator() {
        println!("{}", cipher_text);
    }
}