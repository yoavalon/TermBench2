struct HashSimulator {
    data: String,
    hash: u64,
}

impl HashSimulator {
    fn new(data: &str) -> Self {
        HashSimulator {
            data: data.to_string(),
            hash: 0,
        }
    }

    fn hash_step(&mut self, index: usize) -> u64 {
        if index >= self.data.len() {
            return self.hash;
        }
        let char = self.data.chars().nth(index).unwrap();
        self.hash = (self.hash + (char as u64) * (index as u64 + 1)) % 1000000007;
        self.hash_step(index + 1)
    }

    fn compute_hash(&mut self) -> u64 {
        self.hash_step(0)
    }
}

struct CipherSimulator {
    key: String,
    text: String,
}

impl CipherSimulator {
    fn new(key: &str, text: &str) -> Self {
        CipherSimulator {
            key: key.to_string(),
            text: text.to_string(),
        }
    }

    fn cipher_step(&self, index: usize, result: String) -> String {
        if index >= self.text.len() {
            return result;
        }
        let char = self.text.chars().nth(index).unwrap();
        let key_char = self.key.chars().nth(index % self.key.len()).unwrap();
        let shifted = (char as u8 + key_char as u8) % 256;
        let mut new_result = result.clone();
        new_result.push(shifted as char);
        self.cipher_step(index + 1, new_result)
    }

    fn encrypt(&self) -> String {
        self.cipher_step(0, String::new())
    }
}

fn main() {
    let data = "SecureData2023";
    let mut hash_sim = HashSimulator::new(data);
    let computed_hash = hash_sim.compute_hash();
    let key = "secret";
    let text = "HelloWorld";
    let cipher_sim = CipherSimulator::new(key, text);
    let encrypted_text = cipher_sim.encrypt();
    println!("Computed Hash: {}", computed_hash);
    println!("Encrypted Text: {}", encrypted_text);
}