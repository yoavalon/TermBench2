use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn simulate_cipher(hash_result: String) {
    loop {
        let new_hash = hash_data(&hash_result);
        if new_hash == hash_result {
            break;
        }
        hash_result = new_hash;
    }
}

fn main() {
    let initial_data = "seed";
    let hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
}