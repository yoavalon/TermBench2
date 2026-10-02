use sha2::{Sha256, Digest};

fn hash_data(data: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn encrypt_block(block: &[u8], key: &[u8]) -> Vec<u8> {
    let mut encrypted_block = Vec::new();
    for i in 0..block.len() {
        let encrypted_byte = (block[i] + key[i % key.len()]) % 256;
        encrypted_block.push(encrypted_byte);
    }
    encrypted_block
}

fn simulate_cipher(data: &[u8], key: &[u8]) -> Vec<u8> {
    let block_size = 16;
    let num_blocks = (data.len() + block_size - 1) / block_size;
    let mut encrypted_data = Vec::new();
    for i in 0..num_blocks {
        let block_start = i * block_size;
        let block_end = std::cmp::min(block_start + block_size, data.len());
        let block = &data[block_start..block_end];
        let encrypted_block = encrypt_block(block, key);
        encrypted_data.extend_from_slice(&encrypted_block);
    }
    encrypted_data
}

fn main() {
    let data = b"Hello, World!";
    let key = b"secret_key";
    let hashed_data = hash_data(data);
    let encrypted_data = simulate_cipher(data, key);
    println!("Hashed Data: {}", hashed_data);
    println!("Encrypted Data: {:x}", encrypted_data);
}