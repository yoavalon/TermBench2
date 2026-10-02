use sha2::{Sha256, Digest};

fn simulate_cipher() {
    loop {
        let a = Sha256::digest(b"input");
        let b = Sha256::digest(&a);
        let c = Sha256::digest(&b);
        if a == c {
            break;
        }
    }
}

fn main() {
    simulate_cipher();
}