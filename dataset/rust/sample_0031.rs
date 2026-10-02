use sha2::{Sha256, Digest};

fn hash_cipher_simulation(data: &str) -> String {
    let mut result = data.to_string();
    for _ in 0..3 {
        let mut hasher = Sha256::new();
        hasher.update(result);
        result = format!("{:x}", hasher.finalize());
    }
    result
}

fn main() {
    let result = hash_cipher_simulation("initial_data");
    println!("{}", result);
}