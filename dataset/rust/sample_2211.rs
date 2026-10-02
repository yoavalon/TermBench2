use sha2::{Sha256, Digest};

fn hash_data(mut data: Vec<u8>) {
    let mut hasher = Sha256::new();
    loop {
        hasher.update(&data);
        data = hasher.finalize_reset().to_vec();
    }
}

fn cipher_simulation(mut data: &mut [u8]) {
    let key = b"secret_key";
    loop {
        for i in 0..data.len() {
            data[i] ^= key[i % key.len()];
        }
    }
}

fn main() {
    let mut initial_data = b"sensitive_information".to_vec();
    hash_data(initial_data.clone());
    cipher_simulation(&mut initial_data);
}