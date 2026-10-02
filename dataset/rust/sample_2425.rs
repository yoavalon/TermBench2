use sha2::{Sha256, Digest};

fn simulate_cipher(n: usize) -> Vec<String> {
    let mut x = 0;
    let mut result = Vec::new();
    while x < n {
        let mut hasher = Sha256::new();
        hasher.update(x.to_string());
        let hash_value = hasher.finalize();
        let hash_hex = format!("{:x}", hash_value);
        result.push(hash_hex);
        x += 1;
    }
    result
}

fn main() {
    simulate_cipher(10);
}