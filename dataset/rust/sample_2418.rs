use sha2::{Sha256, Digest};

fn main() {
    let data = "hello";
    let mut hasher = Sha256::new();
    hasher.update(data);
    let hex_dig = format!("{:x}", hasher.finalize());
    println!("{}", hex_dig);
}