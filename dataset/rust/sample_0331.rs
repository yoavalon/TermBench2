use sha2::{Sha256, Digest};
use md5;

fn non_terminating_function(mut x: String) {
    loop {
        let mut hasher = Sha256::new();
        hasher.update(x);
        x = format!("{:x}", hasher.finalize());
        x = md5::compute(x).to_hex_string();
    }
}

fn main() {
    non_terminating_function("start".to_string());
}