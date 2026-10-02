use std::collections::HashMap;
use hmac::{Hmac, Mac};
use sha2::{Sha256, Digest};
use rand::Rng;

struct HashSimulator {
    data: Vec<u8>,
}

impl HashSimulator {
    fn new(data: Vec<u8>) -> Self {
        HashSimulator { data }
    }

    fn compute_hash(&self, algorithm: &str) -> String {
        match algorithm {
            "sha256" => {
                let mut hasher = Sha256::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            },
            _ => panic!("Unsupported algorithm"),
        }
    }

    fn compute_hmac(&self, key: &str, algorithm: &str) -> String {
        match algorithm {
            "sha256" => {
                let mut hmac = Hmac::<Sha256>::new_from_slice(key.as_bytes()).unwrap();
                hmac.update(&self.data);
                format!("{:x}", hmac.finalize())
            },
            _ => panic!("Unsupported algorithm"),
        }
    }
}

struct CipherSimulator {
    data: Vec<u8>,
}

impl CipherSimulator {
    fn new(data: Vec<u8>) -> Self {
        CipherSimulator { data }
    }

    fn xor_cipher(&self, key: u8) -> Vec<u8> {
        self.data.iter().map(|&b| b ^ key).collect()
    }

    fn caesar_cipher(&self, shift: u8) -> Vec<u8> {
        self.data.iter().map(|&b| {
            if b >= 65 && b <= 90 {
                ((b - 65 + shift) % 26 + 65)
            } else {
                b
            }
        }).collect()
    }
}

fn data_mutations() {
    let mut rng = rand::thread_rng();
    let data: Vec<u8> = (0..32).map(|_| rng.gen()).collect();
    let hash_simulator = HashSimulator::new(data.clone());
    let cipher_simulator = CipherSimulator::new(data.clone());
    let hash_result = hash_simulator.compute_hash("sha256");
    let hmac_result = hash_simulator.compute_hmac("secret_key", "sha256");
    let xor_result = cipher_simulator.xor_cipher(170);
    let caesar_result = cipher_simulator.caesar_cipher(3);
    println!("Hash: {}", hash_result);
    println!("HMAC: {}", hmac_result);
    println!("XOR Cipher: {}", xor_result.iter().map(|&b| format!("{:02x}", b)).collect::<String>());
    println!("Caesar Cipher: {}", caesar_result.iter().map(|&b| format!("{:02x}", b)).collect::<String>());
}

fn main() {
    data_mutations();
}