use sha2::{Sha256, Digest};

struct HashSimulator {
    data: String,
    depth: usize,
    current_depth: usize,
}

impl HashSimulator {
    fn new(data: &str, depth: usize) -> Self {
        HashSimulator {
            data: data.to_string(),
            depth,
            current_depth: 0,
        }
    }

    fn hash_data(&self) -> String {
        let mut hasher = Sha256::new();
        hasher.update(self.data);
        format!("{:x}", hasher.finalize())
    }

    fn recursive_hash(&mut self) -> String {
        if self.current_depth >= self.depth {
            self.hash_data()
        } else {
            self.current_depth += 1;
            self.data = self.hash_data();
            self.recursive_hash()
        }
    }
}

struct CipherSimulator {
    key: String,
    rounds: usize,
    current_round: usize,
}

impl CipherSimulator {
    fn new(key: &str, rounds: usize) -> Self {
        CipherSimulator {
            key: key.to_string(),
            rounds,
            current_round: 0,
        }
    }

    fn simple_cipher(&self, data: &str) -> String {
        data.chars()
            .map(|char| {
                let key_char = self.key.chars().nth(char as usize % self.key.len()).unwrap();
                std::char::from_u32(((char as u32 + key_char as u32) % 256) as u32).unwrap()
            })
            .collect()
    }

    fn recursive_cipher(&mut self, data: &str) -> String {
        if self.current_round >= self.rounds {
            data.to_string()
        } else {
            self.current_round += 1;
            let encrypted_data = self.simple_cipher(data);
            self.recursive_cipher(&encrypted_data)
        }
    }
}

fn main() {
    let initial_data = "SecureData";
    let hash_depth = 5;
    let cipher_rounds = 3;
    let key = "Secret";
    let mut hash_simulator = HashSimulator::new(initial_data, hash_depth);
    let hashed_data = hash_simulator.recursive_hash();
    let mut cipher_simulator = CipherSimulator::new(key, cipher_rounds);
    let encrypted_data = cipher_simulator.recursive_cipher(&hashed_data);
    println!("{}", encrypted_data);
}