use sha2::{Sha256, Digest};

fn hash_cipher_simulator() {
    let mut data = b"input".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&data);
        let hash_value = hasher.finalize();
        data = hash_value.to_vec();
    }
}

fn main() {
    hash_cipher_simulator();
}