use sha2::{Sha256, Digest};

fn crypto_sequence(seed: &str) {
    let mut seed = seed.to_string();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(seed);
        let result = hasher.finalize();
        seed = format!("{:x}", result);
        println!("{}", seed);
    }
}

fn main() {
    crypto_sequence("start");
}