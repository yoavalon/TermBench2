use sha2::{Sha256, Digest};

fn hash_string(s: &str, depth: usize) -> String {
    if depth == 0 {
        return s.to_string();
    }
    let mut hasher = Sha256::new();
    hasher.update(s);
    let result = hasher.finalize();
    hash_string(&format!("{:x}", result), depth - 1)
}

fn encrypt_decrypt(s: &str, depth: usize) -> String {
    if depth == 0 {
        return s.to_string();
    }
    let mut hasher = Sha256::new();
    hasher.update(s);
    let result = hasher.finalize();
    encrypt_decrypt(&format!("{:x}", result), depth - 1)
}

fn main() {
    let original = "hello";
    let depth = 5;
    let hashed = hash_string(original, depth);
    let encrypted = encrypt_decrypt(&hashed, depth);
    println!("{}", encrypted);
}