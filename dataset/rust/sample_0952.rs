use sha2::{Sha256, Digest};

fn recursive_hash(x: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(x);
    let result = hasher.finalize();
    let hex = format!("{:x}", result);
    recursive_hash(&hex)
}

fn main() {
    recursive_hash("start");
}