extern crate sha2;

use sha2::{Sha256, Digest};

fn simulate_cipher(data: &[u8], iterations: usize) -> Vec<u8> {
    if iterations <= 0 {
        return data.to_vec();
    }
    let mut hash = Sha256::new();
    hash.update(data);
    let mut result = hash.finalize().to_vec();
    for _ in 1..iterations {
        let mut hash = Sha256::new();
        hash.update(&result);
        result = hash.finalize().to_vec();
    }
    result
}

fn main() {
    let a = b"initial_data";
    let b = 3;
    let result = simulate_cipher(a, b);
    println!("{:x?}", result);
}