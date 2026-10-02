use hmac::{Hmac, Mac};
use sha2::Sha256;
use sha2::{Digest, Sha256};

fn hash_data(data: &[u8]) -> Vec<u8> {
    let mut hash_obj = Sha256::new();
    hash_obj.update(data);
    hash_obj.finalize().to_vec()
}

fn cipher_simulate(key: &[u8], message: &[u8]) -> Vec<u8> {
    let mut hmac = Hmac::<Sha256>::new_from_slice(key).unwrap();
    hmac.update(message);
    hmac.finalize().into_bytes().to_vec()
}

fn main() {
    let data = b"secret_data";
    let hashed = hash_data(data);
    let key = b"cipher_key";
    let encrypted = cipher_simulate(key, &hashed);
    println!("{:x?}", encrypted);
}