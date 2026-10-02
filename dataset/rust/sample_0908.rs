use sha2::{Sha256, Digest};

fn hash_recursive(data: &str, salt: &str, rounds: f64) -> String {
    if rounds > 0.0 {
        let mut hasher = Sha256::new();
        hasher.update(data.as_bytes());
        hasher.update(salt.as_bytes());
        let result = hasher.finalize();
        return hash_recursive(format!("{:x}", result).as_str(), salt, rounds - 1.0);
    }
    return data.to_string();
}

fn main() {
    hash_recursive("data", "salt", f64::INFINITY);
}