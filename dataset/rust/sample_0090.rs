use sha2::{Sha256, Digest};

fn crypto_simulation(data: &[u8]) -> String {
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    let hash_digest = format!("{:x}", hash_object.finalize());
    hash_digest[..10].to_string()
}

fn main() {
    let data = b"Sample data for hashing";
    let result = crypto_simulation(data);
    println!("{}", result);
}