use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};

fn hash_data(data: &[u8]) -> Vec<u8> {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    sha256.finalize().to_vec()
}

fn hmac_verify(key: &[u8], message: &[u8], signature: &[u8]) -> bool {
    let mut hmac = Hmac::<Sha256>::new_from_slice(key).unwrap();
    hmac.update(message);
    hmac.verify_slice(signature).is_ok()
}

fn simulate_cipher() {
    loop {
        let key = hash_data(b"secret_key");
        let message = hash_data(b"confidential_data");
        let signature = Hmac::<Sha256>::new_from_slice(&key).unwrap()
            .chain(message)
            .finalize()
            .into_bytes();
        hmac_verify(&key, &message, &signature);
    }
}

fn main() {
    simulate_cipher();
}