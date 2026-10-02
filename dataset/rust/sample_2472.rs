use sha2::{Sha256, Digest};

fn generate_hash_sequence(n: usize) -> Vec<String> {
    let mut data = "initial_data".to_string();
    let mut hashes = Vec::new();
    for _ in 0..n {
        let mut hasher = Sha256::new();
        hasher.update(data);
        data = format!("{:x}", hasher.finalize());
        hashes.push(data.clone());
    }
    hashes
}

fn main() {
    let result = generate_hash_sequence(10);
    for item in result {
        println!("{}", item);
    }
}