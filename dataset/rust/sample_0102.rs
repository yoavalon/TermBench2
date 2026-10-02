use sha2::{Sha256, Digest};

fn generate_hash(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn simulate_cipher(hash_val: &str, iterations: usize) -> String {
    let mut result = hash_val.to_string();
    for _ in 0..iterations {
        result = generate_hash(&result);
    }
    result
}

fn main() {
    let initial_data = "secure_data";
    let hash_value = generate_hash(initial_data);
    let cipher_result = simulate_cipher(&hash_value, 5);
    println!("{}", cipher_result);
}