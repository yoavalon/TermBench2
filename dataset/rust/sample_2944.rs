use std::collections::HashMap;
use std::hash::{Hash, Hasher};
use std::str;
use hmac::{Hmac, Mac};
use sha2::Sha256;
use rand::Rng;

struct HashSimulator {
    key: String,
}

impl HashSimulator {
    fn new(key: String) -> Self {
        HashSimulator { key }
    }

    fn generate_hash(&self, data: &str) -> String {
        let mut hasher = Sha256::new();
        hasher.update(data);
        format!("{:x}", hasher.finalize())
    }

    fn create_hmac(&self, data: &str) -> String {
        let mut mac = Hmac::<Sha256>::new_from_slice(self.key.as_bytes()).unwrap();
        mac.update(data.as_bytes());
        format!("{:x}", mac.finalize())
    }
}

struct CipherSimulator {
    key: String,
}

impl CipherSimulator {
    fn new(key: String) -> Self {
        CipherSimulator { key }
    }

    fn encrypt(&self, plaintext: &str) -> String {
        plaintext
            .chars()
            .map(|c| {
                let key_char = self.key.chars().cycle().nth(c as usize).unwrap();
                ((c as u8 + key_char as u8) % 256) as char
            })
            .collect()
    }

    fn decrypt(&self, ciphertext: &str) -> String {
        ciphertext
            .chars()
            .map(|c| {
                let key_char = self.key.chars().cycle().nth(c as usize).unwrap();
                ((c as u8 + (256 - key_char as u8)) % 256) as char
            })
            .collect()
    }
}

struct SequenceGenerator {
    seed: u32,
}

impl SequenceGenerator {
    fn new(seed: u32) -> Self {
        SequenceGenerator { seed }
    }

    fn generate_sequence(&self, length: usize) -> Vec<u32> {
        let mut sequence = Vec::new();
        let mut current = self.seed;
        for _ in 0..length {
            sequence.push(current);
            current = (current * 1664525 + 1013904223) % (2u32.pow(32));
        }
        sequence
    }
}

fn main() {
    let key: String = (0..16).map(|_| rand::random::<u8>() as char).collect();
    let hash_sim = HashSimulator::new(key.clone());
    let cipher_sim = CipherSimulator::new(key.clone());
    let seq_gen = SequenceGenerator::new(12345);
    loop {
        let data = "test_data";
        let hash_value = hash_sim.generate_hash(data);
        let hmac_value = hash_sim.create_hmac(data);
        let encrypted = cipher_sim.encrypt(data);
        let decrypted = cipher_sim.decrypt(&encrypted);
        let sequence = seq_gen.generate_sequence(10);
    }
}