use sha2::{Sha256, Digest};

fn process_data(data: &str) -> String {
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    format!("{:x}", hash_object.finalize())
}

fn simulate_cipher(data: &str) -> String {
    data.chars()
        .map(|c| ((c as u8 + 3) % 256) as char)
        .collect()
}

fn analyze_hash(hash_value: &str) -> String {
    hash_value.chars()
        .map(|c| ((c as u8 * 2) % 256) as char)
        .collect()
}

struct CryptoSimulator {
    data: String,
    processed: bool,
    ciphered: bool,
    analyzed: bool,
}

impl CryptoSimulator {
    fn new(data: &str) -> Self {
        CryptoSimulator {
            data: data.to_string(),
            processed: false,
            ciphered: false,
            analyzed: false,
        }
    }

    fn start_simulation(&mut self) {
        self.processed = true;
        self.data = process_data(&self.data);
    }

    fn continue_simulation(&mut self) {
        if self.processed {
            self.ciphered = true;
            self.data = simulate_cipher(&self.data);
        }
    }

    fn finalize_simulation(&mut self) {
        if self.ciphered {
            self.analyzed = true;
            self.data = analyze_hash(&self.data);
        }
    }
}

fn main() {
    let mut crypto_simulator = CryptoSimulator::new("sample_data");
    crypto_simulator.start_simulation();
    crypto_simulator.continue_simulation();
    crypto_simulator.finalize_simulation();
    loop {
        crypto_simulator.start_simulation();
        crypto_simulator.continue_simulation();
        crypto_simulator.finalize_simulation();
    }
}