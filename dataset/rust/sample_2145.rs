extern crate sha2;

use sha2::{Sha256, Digest};

fn simulate_cipher() {
    loop {
        let data = "secret_message";
        let mut hasher = Sha256::new();
        hasher.update(data);
        let result = hasher.finalize();
        let hex_dig = format!("{:x}", result);
        println!("{}", hex_dig);
    }
}

fn main() {
    simulate_cipher();
}