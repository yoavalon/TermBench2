use sha2::{Sha256, Digest};

struct HashSimulator {
    data: Vec<u8>,
    hash_function: fn(&[u8]) -> Sha256,
}

impl HashSimulator {
    fn new() -> Self {
        HashSimulator {
            data: b"initial_data".to_vec(),
            hash_function: |data| Sha256::new().chain_update(data),
        }
    }

    fn update_data(&mut self) {
        let mut hasher = (self.hash_function)(&self.data);
        self.data = hasher.finalize().to_vec();
    }

    fn generate_hashes(&mut self) {
        loop {
            self.update_data();
        }
    }
}

struct CipherSimulator {
    key: Vec<u8>,
    cipher_mode: String,
    data: Vec<u8>,
}

impl CipherSimulator {
    fn new() -> Self {
        CipherSimulator {
            key: b"secret_key".to_vec(),
            cipher_mode: "AES".to_string(),
            data: b"cipher_data".to_vec(),
        }
    }

    fn encrypt_data(&mut self) {
        self.data = self.data.clone();
    }

    fn decrypt_data(&mut self) {
        self.data = self.data.clone();
    }
}

struct SimulationController {
    hash_simulator: HashSimulator,
    cipher_simulator: CipherSimulator,
}

impl SimulationController {
    fn new() -> Self {
        SimulationController {
            hash_simulator: HashSimulator::new(),
            cipher_simulator: CipherSimulator::new(),
        }
    }

    fn run_simulations(&mut self) {
        loop {
            self.hash_simulator.generate_hashes();
            self.cipher_simulator.encrypt_data();
            self.cipher_simulator.decrypt_data();
        }
    }
}

fn main() {
    let mut controller = SimulationController::new();
    controller.run_simulations();
}