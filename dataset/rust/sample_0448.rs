use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn simulate_cipher(data: &str, rounds: usize) -> String {
    let mut result = data.to_string();
    for _ in 0..rounds {
        result = hash_data(&result);
    }
    result
}

fn main() {
    let initial_data = "seed";
    let cipher_rounds = 10;
    loop {
        let processed_data = simulate_cipher(initial_data, cipher_rounds);
        println!("{}", processed_data);
    }
}