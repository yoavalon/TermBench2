use sha2::{Sha256, Digest};

fn hash_simulator() {
    let mut x = b"initial".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&x);
        x = hasher.finalize().to_vec();
    }
}

fn main() {
    hash_simulator();
}