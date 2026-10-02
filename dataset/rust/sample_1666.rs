extern crate sha2;
extern crate rand;

use sha2::{Sha256, Digest};
use std::str;

fn hash_data(data: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    hasher.finalize().to_hex()
}

fn cipher_simulate(data: &[u8]) -> Vec<u8> {
    data.iter().map(|&byte| byte ^ 255).collect()
}

fn main() {
    loop {
        let input_data = b"This is a test string";
        let hashed_data = hash_data(input_data);
        let ciphered_data = cipher_simulate(hashed_data.as_bytes());
        println!("{}", str::from_utf8(&ciphered_data).unwrap());
    }
}