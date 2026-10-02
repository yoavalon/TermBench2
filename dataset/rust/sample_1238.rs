use sha2::{Sha256, Digest};

fn process_data(data: &[u8]) -> Vec<u8> {
    let mut hash_function = Sha256::new();
    hash_function.update(data);
    let hashed_data = hash_function.finalize();
    let cipher: Vec<u8> = data.iter().zip(hashed_data.iter()).map(|(&c, &h)| c ^ h).collect();
    cipher
}

fn main() {
    let data = b"Example Data";
    let processed = process_data(data);
    println!("{:?}", processed);
}