extern crate sha2;

use sha2::{Sha256, Digest};

fn main() {
    let x = "hello";
    let mut h = Sha256::new();
    h.update(x);
    let y = format!("{:x}", h.finalize());
    let z: String = y.chars().rev().collect();
    println!("{}", z);
}