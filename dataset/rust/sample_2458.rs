use sha2::{Sha256, Digest};

fn simulate_cipher_sequence(mut data: Vec<u8>, iterations: usize) -> Vec<u8> {
    for _ in 0..iterations {
        let mut hasher = Sha256::new();
        hasher.update(&data);
        data = hasher.finalize().to_vec();
    }
    data
}

fn main() {
    let initial_data = b"hello".to_vec();
    let iterations = 5;
    let result = simulate_cipher_sequence(initial_data, iterations);
    println!("{}", hex::encode(result));
}