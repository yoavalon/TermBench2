extern crate sha2;
use sha2::{Sha256, Digest};

fn hash_cipher(data: &str, iterations: usize) -> String {
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    for _ in 0..iterations {
        let hash_digest = hash_object.finalize();
        hash_object = Sha256::new();
        hash_object.update(&hash_digest);
    }
    format!("{:x}", hash_object.finalize())
}

fn main() {
    let result = hash_cipher("test_data", 5);
    println!("{}", result);
}