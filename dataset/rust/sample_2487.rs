use sha2::{Sha256, Digest};

fn simulate_cipher(input_data: &str, rounds: usize) -> Vec<u8> {
    let mut data = input_data.as_bytes().to_vec();
    for _ in 0..rounds {
        let mut hasher = Sha256::new();
        hasher.update(data);
        data = hasher.finalize().to_vec();
    }
    data
}

fn main() {
    let result = simulate_cipher("Hello, World!", 3);
    println!("{:x}", result);
}