use sha2::{Sha256, Digest};

struct HashSimulator {
    data: String,
    hash_values: Vec<String>,
}

impl HashSimulator {
    fn new(data: &str) -> HashSimulator {
        HashSimulator {
            data: data.to_string(),
            hash_values: Vec::new(),
        }
    }

    fn generate_hashes(&mut self, rounds: usize) {
        for _ in 0..rounds {
            let mut hasher = Sha256::new();
            hasher.update(self.data.as_bytes());
            let result = hasher.finalize();
            self.data = format!("{:x}", result);
            self.hash_values.push(self.data.clone());
        }
    }

    fn get_hash_sequence(&self) -> &Vec<String> {
        &self.hash_values
    }
}

struct CipherSimulator {
    key: String,
    encrypted_values: Vec<String>,
}

impl CipherSimulator {
    fn new(key: &str) -> CipherSimulator {
        CipherSimulator {
            key: key.to_string(),
            encrypted_values: Vec::new(),
        }
    }

    fn encrypt(&mut self, value: &str) {
        let encrypted_value: String = value.chars().enumerate().map(|(i, c)| {
            let key_char = self.key.chars().nth(i % self.key.len()).unwrap();
            let encrypted_char = ((c as u8 + key_char as u8) % 256) as char;
            encrypted_char
        }).collect();
        self.encrypted_values.push(encrypted_value);
    }

    fn get_encrypted_sequence(&self) -> &Vec<String> {
        &self.encrypted_values
    }
}

fn main() {
    let initial_data = "seed";
    let hash_rounds = 5;
    let cipher_key = "key";
    let mut hash_sim = HashSimulator::new(initial_data);
    hash_sim.generate_hashes(hash_rounds);
    let hash_sequence = hash_sim.get_hash_sequence();
    let mut cipher_sim = CipherSimulator::new(cipher_key);
    for hash_value in hash_sequence {
        cipher_sim.encrypt(hash_value);
    }
    let encrypted_sequence = cipher_sim.get_encrypted_sequence();
    println!("{:?}", encrypted_sequence);
}