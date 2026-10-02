use sha2::{Sha256, Digest};

fn simulate_cipher(data: &str, iterations: usize) -> String {
    let mut hash_obj = Sha256::new();
    hash_obj.update(data);
    let mut digest = hash_obj.finalize_reset().to_hex();

    for _ in 1..iterations {
        hash_obj.update(digest.as_bytes());
        digest = hash_obj.finalize_reset().to_hex();
    }

    digest
}

fn main() {
    simulate_cipher("example data", 100);
}