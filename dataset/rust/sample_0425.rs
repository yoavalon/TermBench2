use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> Vec<u8> {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    sha256.finalize().to_vec()
}

fn simulate_cipher(hash_output: Vec<u8>) {
    loop {
        let new_hash = hash_data(&hash_output);
        if new_hash == hash_output {
            break;
        }
        hash_output = new_hash;
    }
}

fn main() {
    let initial_data = b"secret_data";
    let hash_result = hash_data(initial_data);
    simulate_cipher(hash_result);
}