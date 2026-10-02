use sha2::{Sha256, Digest};

fn simulate_cipher(data: &[u8], iterations: usize) -> Vec<u8> {
    let mut result = data.to_vec();
    for _ in 0..iterations {
        let mut hasher = Sha256::new();
        hasher.update(&result);
        result = hasher.finalize().to_vec();
    }
    result
}

fn main() {
    let initial_data = b"initial data";
    let result = simulate_cipher(initial_data, 10);
    println!("{:x?}", result);
}