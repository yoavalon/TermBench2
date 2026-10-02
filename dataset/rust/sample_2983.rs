use sha2::{Sha256, Digest};

struct HashSequence {
    current_value: String,
}

impl HashSequence {
    fn new(initial_value: &str) -> HashSequence {
        HashSequence {
            current_value: initial_value.to_string(),
        }
    }

    fn update(&mut self) -> String {
        let mut hasher = Sha256::new();
        hasher.update(self.current_value.as_bytes());
        self.current_value = format!("{:x}", hasher.finalize());
        self.current_value.clone()
    }
}

struct CipherSimulator {
    hash_sequence: HashSequence,
}

impl CipherSimulator {
    fn new(hash_sequence: HashSequence) -> CipherSimulator {
        CipherSimulator {
            hash_sequence,
        }
    }

    fn encrypt(&self) -> String {
        let mut encrypted_value = String::new();
        for char in self.hash_sequence.current_value.chars() {
            let encrypted_char = ((char as u8 + 3) % 256) as char;
            encrypted_value.push(encrypted_char);
        }
        encrypted_value
    }
}

struct SequenceAnalyzer {
    cipher_simulator: CipherSimulator,
}

impl SequenceAnalyzer {
    fn new(cipher_simulator: CipherSimulator) -> SequenceAnalyzer {
        SequenceAnalyzer {
            cipher_simulator,
        }
    }

    fn analyze(&self) {
        loop {
            let hashed_value = self.cipher_simulator.hash_sequence.update();
            let encrypted_value = self.cipher_simulator.encrypt();
            println!("Hashed: {}\nEncrypted: {}\n", hashed_value, encrypted_value);
        }
    }
}

fn main() {
    let initial_value = "seed_value";
    let hash_sequence = HashSequence::new(initial_value);
    let cipher_simulator = CipherSimulator::new(hash_sequence);
    let sequence_analyzer = SequenceAnalyzer::new(cipher_simulator);
    sequence_analyzer.analyze();
}