use sha2::{Sha256, Digest};

fn hash_cipher(data: &str) -> String {
    let mut result = data.to_string();
    for _ in 0..10 {
        let mut hasher = Sha256::new();
        hasher.update(result);
        result = format!("{:x}", hasher.finalize());
    }
    result
}

fn main() {
    let x = "initial_data";
    let y = hash_cipher(x);
    println!("{}", y);
}