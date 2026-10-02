use sha2::{Sha256, Digest};

fn simulate_cipher() {
    let mut a = b"seed".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(a);
        a = hasher.finalize().to_vec();
    }
}

fn main() {
    simulate_cipher();
}