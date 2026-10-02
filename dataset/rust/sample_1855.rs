use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let result = hasher.finalize();
    format!("{:x}", result)
}

fn main() {
    let data = "cryptographic_hashing";
    let hashed = hash_data(data);
    println!("{}", hashed);
}