extern crate sha2;
extern crate md5;

use sha2::{Sha256, Digest};
use md5::Md5;

fn cryptographic_simulations() {
    let x = b"Hello, World!";
    let mut hasher = Sha256::new();
    hasher.update(x);
    let y = hasher.finalize();
    let y_hex = format!("{:x}", y);

    let mut hasher = Md5::new();
    hasher.update(x);
    let z = hasher.finalize();
    let z_hex = format!("{:x}", z);

    let a = format!("{}{}", z_hex, y_hex);
    let mut hasher = Sha256::new();
    hasher.update(a);
    let b = hasher.finalize();
    let b_hex = format!("{:x}", b);

    let c = &b_hex[..10];
    println!("{}", c);
}

fn main() {
    cryptographic_simulations();
}