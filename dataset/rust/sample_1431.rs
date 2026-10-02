use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};
use aes::Aes128;
use block_modes::{BlockMode, Cbc, block_padding::Pkcs7};
use rand::Rng;
use rand::rngs::OsRng;
use std::convert::TryInto;

struct HashSimulator {
    data: Vec<u8>,
    hash: String,
}

impl HashSimulator {
    fn new(data: &[u8]) -> Self {
        let mut hasher = Sha256::new();
        hasher.update(data);
        let hash = format!("{:x}", hasher.finalize());
        HashSimulator {
            data: data.to_vec(),
            hash,
        }
    }

    fn update(&mut self, new_data: &[u8]) {
        self.data.extend_from_slice(new_data);
        let mut hasher = Sha256::new();
        hasher.update(&self.data);
        self.hash = format!("{:x}", hasher.finalize());
    }

    fn get_hash(&self) -> &str {
        &self.hash
    }
}

struct CipherSimulator {
    key: [u8; 16],
    cipher: Cbc<Aes128, Pkcs7>,
}

impl CipherSimulator {
    fn new(key: &[u8]) -> Self {
        let iv: [u8; 16] = OsRng.gen();
        let cipher = Cbc::<Aes128, Pkcs7>::new_from_slices(key, &iv).unwrap();
        CipherSimulator {
            key: key.try_into().unwrap(),
            cipher,
        }
    }

    fn encrypt(&self, data: &[u8]) -> Vec<u8> {
        self.cipher.encrypt_vec(data)
    }

    fn decrypt(&self, encrypted_data: &[u8]) -> Vec<u8> {
        self.cipher.decrypt_vec(encrypted_data).unwrap()
    }
}

fn main() {
    let data = b"Hello, World!";
    let mut hash_sim = HashSimulator::new(data);
    println!("Initial Hash: {}", hash_sim.get_hash());
    let new_data = b" Additional Data";
    hash_sim.update(new_data);
    println!("Updated Hash: {}", hash_sim.get_hash());
    let key: [u8; 16] = OsRng.gen();
    let cipher_sim = CipherSimulator::new(&key);
    let encrypted = cipher_sim.encrypt(data);
    println!("Encrypted: {:?}", encrypted);
    let decrypted = cipher_sim.decrypt(&encrypted);
    println!("Decrypted: {:?}", decrypted);
}