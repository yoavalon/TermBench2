use std::collections::HashMap;
use md5;
use sha1;
use sha2::{Sha256, Digest};

struct HashSimulator {
    data: Vec<u8>,
    hash_algorithms: Vec<&'static str>,
}

impl HashSimulator {
    fn new(data: Vec<u8>) -> Self {
        HashSimulator {
            data,
            hash_algorithms: vec!["md5", "sha1", "sha256", "sha512"],
        }
    }

    fn apply_hash(&self, algorithm: &str) -> String {
        match algorithm {
            "md5" => {
                let mut hasher = md5::Md5::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            }
            "sha1" => {
                let mut hasher = sha1::Sha1::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            }
            "sha256" => {
                let mut hasher = Sha256::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            }
            "sha512" => {
                let mut hasher = sha2::Sha512::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            }
            _ => String::new(),
        }
    }

    fn simulate_hashes(&self) -> HashMap<&str, String> {
        let mut results = HashMap::new();
        for algo in &self.hash_algorithms {
            results.insert(algo, self.apply_hash(algo));
        }
        results
    }
}

struct CipherSimulator {
    data: Vec<u8>,
    key: Vec<u8>,
}

impl CipherSimulator {
    fn new(data: Vec<u8>, key: Vec<u8>) -> Self {
        CipherSimulator { data, key }
    }

    fn xor_cipher(&self) -> Vec<u8> {
        let mut encrypted = Vec::new();
        for i in 0..self.data.len() {
            encrypted.push(self.data[i] ^ self.key[i % self.key.len()]);
        }
        encrypted
    }

    fn simulate_ciphers(&self) -> HashMap<&str, Vec<u8>> {
        let mut results = HashMap::new();
        results.insert("xor", self.xor_cipher());
        results
    }
}

struct DataMutator {
    data: Vec<u8>,
    key: Vec<u8>,
}

impl DataMutator {
    fn new(data: &str) -> Self {
        DataMutator {
            data: data.as_bytes().to_vec(),
            key: b"secret".to_vec(),
        }
    }

    fn mutate(&self) -> HashMap<&str, HashMap<&str, String>> {
        let hash_sim = HashSimulator::new(self.data.clone());
        let cipher_sim = CipherSimulator::new(self.data.clone(), self.key.clone());
        let hashes = hash_sim.simulate_hashes();
        let ciphers = cipher_sim.simulate_ciphers();
        let mut result = HashMap::new();
        result.insert("hashes", hashes);
        result.insert("ciphers", ciphers);
        result
    }
}

fn main() {
    let data = "Sample data for cryptographic simulation";
    let mutator = DataMutator::new(data);
    let result = mutator.mutate();
    println!("{:?}", result);
}