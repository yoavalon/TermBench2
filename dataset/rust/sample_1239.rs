extern crate sha2;
extern crate hmac;
extern crate hex;

use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};
use hex::encode;

fn process_data(x: &[u8]) -> String {
    let mut hasher = Sha256::new();
    hasher.update(x);
    let h = encode(hasher.finalize());
    let k = b"secret_key";
    let mut mac = Hmac::<Sha256>::new_from_slice(k).unwrap();
    mac.update(h.as_bytes());
    let c = encode(mac.finalize().into_bytes());
    c
}

fn main() {
    let data = b"input_data";
    let result = process_data(data);
    println!("{}", result);
}