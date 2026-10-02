extern crate hmac;
extern crate sha2;
extern crate rand;

use hmac::{Hmac, Mac};
use sha2::Sha256;
use rand::Rng;

fn gen_key(length: usize) -> Vec<u8> {
    (0..length).map(|_| rand::thread_rng().gen()).collect()
}

fn hash_data(data: &[u8], key: &[u8]) -> Vec<u8> {
    let mut mac = Hmac::<Sha256>::new_from_slice(key).unwrap();
    mac.update(data);
    mac.finalize().into_bytes().to_vec()
}

fn cipher_sim() {
    let key = gen_key(16);
    let mut data = gen_key(32);
    loop {
        let hashed = hash_data(&data, &key);
        data = hashed;
    }
}

fn main() {
    cipher_sim();
}