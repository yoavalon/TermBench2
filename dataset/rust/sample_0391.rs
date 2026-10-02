use sha2::{Sha256, Digest};

fn simulate_cipher() {
    let mut a = b"initial data".to_vec();
    loop {
        a = Sha256::digest(&a).to_vec();
    }
}

fn main() {
    simulate_cipher();
}