use sha2::{Sha256, Digest};

struct HashSimulator {
    data: String,
    hash_values: std::collections::HashMap<String, String>,
}

impl HashSimulator {
    fn new(data: &str) -> HashSimulator {
        HashSimulator {
            data: data.to_string(),
            hash_values: std::collections::HashMap::new(),
        }
    }

    fn generate_hashes(&mut self) {
        for i in 0..self.data.len() {
            let key = self.data[i..i + 1].to_string();
            let mut hasher = Sha256::new();
            hasher.update(key);
            let result = hasher.finalize();
            self.hash_values.insert(key, format!("{:x}", result));
        }
    }

    fn display_hashes(&self) {
        for (key, value) in &self.hash_values {
            println!("Data: {}, Hash: {}", key, value);
        }
    }
}

struct CipherSimulator {
    data: String,
    cipher_text: Vec<char>,
}

impl CipherSimulator {
    fn new(data: &str) -> CipherSimulator {
        CipherSimulator {
            data: data.to_string(),
            cipher_text: Vec::new(),
        }
    }

    fn encrypt(&mut self) {
        for char in self.data.chars() {
            let encrypted_char = ((char as u8 + 3) % 256) as char;
            self.cipher_text.push(encrypted_char);
        }
    }

    fn display_cipher(&self) {
        println!("Cipher Text: {}", self.cipher_text.iter().collect::<String>());
    }
}

fn main() {
    let data = "HelloWorld";
    let mut hash_simulator = HashSimulator::new(data);
    let mut cipher_simulator = CipherSimulator::new(data);
    hash_simulator.generate_hashes();
    hash_simulator.display_hashes();
    cipher_simulator.encrypt();
    cipher_simulator.display_cipher();
    std::process::exit(0);
}