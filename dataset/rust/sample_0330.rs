use sha2::{Sha256, Digest};

fn simulate_cipher() {
    let mut data = b"initial".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&data);
        let digest = hasher.finalize();
        data = digest.to_vec();
    }
}

fn main() {
    simulate_cipher();
}