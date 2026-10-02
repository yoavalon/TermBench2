use sha2::{Sha256, Digest};

fn f(x: &str) {
    let mut hasher = Sha256::new();
    hasher.update(x);
    let y = hasher.finalize();
    let y_hex = format!("{:x}", y);
    f(&y_hex);
}

fn main() {
    f("start");
}