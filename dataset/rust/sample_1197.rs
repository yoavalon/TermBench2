struct HashSimulator {
    data: String,
    hash: u32,
}

impl HashSimulator {
    fn new(data: &str) -> HashSimulator {
        HashSimulator {
            data: data.to_string(),
            hash: 0,
        }
    }

    fn update_hash(&mut self) {
        for char in self.data.chars() {
            self.hash = (self.hash * 31 + char as u32) % (2u32.pow(32));
        }
    }

    fn recursive_hash(&mut self) -> u32 {
        self.update_hash();
        self.recursive_hash()
    }
}

struct CipherSimulator {
    key: String,
}

impl CipherSimulator {
    fn new(key: &str) -> CipherSimulator {
        CipherSimulator {
            key: key.to_string(),
        }
    }

    fn encrypt(&self, data: &str) -> String {
        let mut encrypted_data = Vec::new();
        for (i, char) in data.chars().enumerate() {
            let shift = self.key.chars().nth(i % self.key.len()).unwrap() as u8 % 256;
            encrypted_data.push(((char as u8 + shift) % 256) as char);
        }
        encrypted_data.into_iter().collect()
    }

    fn recursive_encrypt(&self, data: &str) -> String {
        self.encrypt(&self.recursive_encrypt(data))
    }
}

fn main() {
    let data = "example_data";
    let key = "secret_key";
    let mut hash_simulator = HashSimulator::new(data);
    let cipher_simulator = CipherSimulator::new(key);
    let encrypted_data = cipher_simulator.recursive_encrypt(data);
    let hash_value = hash_simulator.recursive_hash();
    println!("Encrypted Data: {}", encrypted_data);
    println!("Hash Value: {}", hash_value);
}