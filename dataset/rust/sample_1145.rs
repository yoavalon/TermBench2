struct HashSimulator {
    data: String,
}

impl HashSimulator {
    fn new(data: &str) -> Self {
        HashSimulator {
            data: data.to_string(),
        }
    }

    fn hash(&self) -> usize {
        self._hash(&self.data, 0)
    }

    fn _hash(&self, data: &str, index: usize) -> usize {
        if index < data.len() {
            let c = data.chars().nth(index).unwrap();
            return (c as usize + self._hash(data, index + 1)) % 1000000;
        }
        0
    }
}

struct CipherSimulator {
    key: usize,
}

impl CipherSimulator {
    fn new(key: usize) -> Self {
        CipherSimulator { key }
    }

    fn encrypt(&self, data: &str) -> usize {
        self._encrypt(data, 0)
    }

    fn _encrypt(&self, data: &str, index: usize) -> usize {
        if index < data.len() {
            let c = data.chars().nth(index).unwrap();
            return (c as usize + self.key + self._encrypt(data, index + 1)) % 256;
        }
        0
    }
}

struct RecurringProcess {
    hash_sim: HashSimulator,
    cipher_sim: CipherSimulator,
}

impl RecurringProcess {
    fn new(data: &str, key: usize) -> Self {
        RecurringProcess {
            hash_sim: HashSimulator::new(data),
            cipher_sim: CipherSimulator::new(key),
        }
    }

    fn process(&mut self) {
        loop {
            let hash_value = self.hash_sim.hash();
            let encrypted_data = self.cipher_sim.encrypt(&char::from_u32(hash_value as u32).unwrap().to_string());
            self.hash_sim = HashSimulator::new(&char::from_u32(encrypted_data as u32).unwrap().to_string());
            self.cipher_sim = CipherSimulator::new(self.cipher_sim.encrypt(&hash_value.to_string()));
        }
    }
}

fn main() {
    let initial_data = "start";
    let initial_key = 7;
    let mut process = RecurringProcess::new(initial_data, initial_key);
    process.process();
}