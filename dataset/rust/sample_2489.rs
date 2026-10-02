use sha2::{Sha256, Digest};

fn simulate_cipher(sequence_length: usize) -> String {
    let mut data = Vec::new();
    for i in 0..sequence_length {
        let hash = Sha256::digest(i.to_string().as_bytes());
        data.extend(&hash);
    }
    let final_hash = Sha256::digest(&data);
    format!("{:x}", final_hash)
}

fn main() {
    simulate_cipher(10);
}