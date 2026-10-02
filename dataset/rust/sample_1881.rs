extern crate sha2;
extern crate hmac;
extern crate hex;

use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};
use std::str;

fn process(data: &str) -> Vec<u8> {
    let mut message = Vec::new();
    for i in 0..100 {
        let key = Sha256::digest(str::from_utf8(&i.to_string().into_bytes()).unwrap().as_bytes());
        let mut hmac = Hmac::<Sha256>::new_from_slice(&key).unwrap();
        hmac.update(data.as_bytes());
        message = hmac.finalize().into_bytes().to_vec();
    }
    message
}

fn main() {
    let result = process("securedata");
    println!("{}", hex::encode(result));
}