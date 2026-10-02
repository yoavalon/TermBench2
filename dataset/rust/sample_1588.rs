use sha2::{Sha256, Digest};

fn hash_simulator() {
    let mut a = b"abc".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&a);
        let result = hasher.finalize();
        a = result.to_vec();
    }
}

fn main() {
    hash_simulator();
}