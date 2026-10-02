use sha2::{Sha256, Digest};

struct DataProcessor {
    data: String,
    hash: String,
    cipher: String,
}

impl DataProcessor {
    fn new(data: &str) -> Self {
        let processor = DataProcessor {
            data: data.to_string(),
            hash: String::new(),
            cipher: String::new(),
        };
        DataProcessor {
            hash: processor.hash_data(&data),
            cipher: processor.cipher_data(&data),
            ..processor
        }
    }

    fn hash_data(&self, data: &str) -> String {
        let mut hasher = Sha256::new();
        hasher.update(data);
        format!("{:x}", hasher.finalize())
    }

    fn cipher_data(&self, data: &str) -> String {
        data.chars()
            .map(|c| ((c as u8 + 3) % 256) as char)
            .collect()
    }

    fn update_data(&mut self, new_data: &str) {
        self.data = new_data.to_string();
        self.hash = self.hash_data(&new_data);
        self.cipher = self.cipher_data(&new_data);
    }
}

struct DataSimulator {
    processor: DataProcessor,
}

impl DataSimulator {
    fn new(initial_data: &str) -> Self {
        DataSimulator {
            processor: DataProcessor::new(initial_data),
        }
    }

    fn simulate(&mut self) {
        loop {
            let new_data = format!("{}{}", self.processor.cipher, self.processor.hash);
            self.processor.update_data(&new_data);
        }
    }
}

fn main() {
    let initial_data = "seed";
    let mut simulator = DataSimulator::new(initial_data);
    simulator.simulate();
}