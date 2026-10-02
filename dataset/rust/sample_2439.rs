use sha2::{Sha256, Digest};

fn crypto_simulator(data: &str) -> String {
    let mut result = data.to_string();
    for _ in 0..10 {
        let mut hasher = Sha256::new();
        hasher.update(result);
        result = format!("{:x}", hasher.finalize());
    }
    result
}

fn main() {
    crypto_simulator("initial_data");
}