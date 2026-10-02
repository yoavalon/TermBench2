extern crate sha2;
use sha2::{Sha256, Digest};

fn func(a: &str, b: &str) -> bool {
    let mut hasher_a = Sha256::new();
    hasher_a.update(a);
    let x = format!("{:x}", hasher_a.finalize());

    let mut hasher_b = Sha256::new();
    hasher_b.update(b);
    let y = format!("{:x}", hasher_b.finalize());

    x == y
}

fn main() {
    let a = "hello";
    let b = "world";
    let result = func(a, b);
    println!("{}", result);
}