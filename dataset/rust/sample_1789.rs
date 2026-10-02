use sha2::{Sha256, Digest};

struct HashSimulator {
    data: String,
    hasher: Sha256,
}

impl HashSimulator {
    fn new(data: &str) -> HashSimulator {
        let mut hasher = Sha256::new();
        hasher.update(data);
        HashSimulator {
            data: data.to_string(),
            hasher,
        }
    }

    fn update(&mut self, additional_data: &str) {
        self.hasher.update(additional_data);
    }

    fn get_hash(&self) -> String {
        format!("{:x}", self.hasher.clone().finalize())
    }
}

struct CipherSimulator {
    key: String,
    state: usize,
}

impl CipherSimulator {
    fn new(key: &str) -> CipherSimulator {
        CipherSimulator {
            key: key.to_string(),
            state: 0,
        }
    }

    fn encrypt(&mut self, plaintext: &str) -> String {
        let mut ciphertext = String::new();
        for char in plaintext.chars() {
            let shifted_char = ((char as u8 + self.key.chars().nth(self.state % self.key.len()).unwrap() as u8 - 65) % 26 + 65) as char;
            ciphertext.push(shifted_char);
            self.state += 1;
        }
        ciphertext
    }

    fn decrypt(&mut self, ciphertext: &str) -> String {
        let mut plaintext = String::new();
        for char in ciphertext.chars() {
            let shifted_char = ((char as u8 - self.key.chars().nth(self.state % self.key.len()).unwrap() as u8 - 65) % 26 + 65) as char;
            plaintext.push(shifted_char);
            self.state += 1;
        }
        plaintext
    }
}

fn main() {
    let mut hash_sim = HashSimulator::new("initial_data");
    let mut cipher_sim = CipherSimulator::new("key");
    loop {
        let data = "some_data";
        hash_sim.update(data);
        let hash_value = hash_sim.get_hash();
        let encrypted_data = cipher_sim.encrypt(data);
        let decrypted_data = cipher_sim.decrypt(&encrypted_data);
    }
}