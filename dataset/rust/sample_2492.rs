use sha2::{Sha256, Digest};

fn generate_hash_sequence(seed: &str, length: usize) -> Vec<String> {
    let mut sequence = Vec::new();
    let mut current_seed = seed.to_string();

    for _ in 0..length {
        let mut hasher = Sha256::new();
        hasher.update(current_seed);
        let result = hasher.finalize();
        let hash_hex = format!("{:x}", result);
        sequence.push(hash_hex);
        current_seed = hash_hex;
    }

    sequence
}

fn main() {
    let sequence = generate_hash_sequence("start", 10);
    for hash in sequence {
        println!("{}", hash);
    }
}