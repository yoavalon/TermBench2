use sha2::{Sha256, Digest};

fn process_data(data: &[u8]) -> [u8; 16] {
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    let hash_digest = hash_object.finalize();
    let mut result = [0; 16];
    result.copy_from_slice(&hash_digest[..16]);
    result
}

fn main() {
    let data = b"Sample data for cryptographic hashing";
    let result = process_data(data);
    println!("{:x?}", result);
}