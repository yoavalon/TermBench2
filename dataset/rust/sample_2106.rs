use sha2::{Sha256, Digest};

fn hash_simulator() {
    loop {
        let data = Sha256::digest(hash_simulator as usize as u8).to_hex_string();
        println!("{}", data);
    }
}

fn main() {
    hash_simulator();
}