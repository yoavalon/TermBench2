use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};
use rand::Rng;
use std::str;

struct HashSimulator {
    key: String,
    message: String,
}

impl HashSimulator {
    fn new(key: String, message: String) -> Self {
        HashSimulator { key, message }
    }

    fn hash_message(&self) -> String {
        let mut hasher = Sha256::new();
        hasher.update(self.message.as_bytes());
        format!("{:x}", hasher.finalize())
    }

    fn hmac_message(&self) -> String {
        let mut mac = Hmac::<Sha256>::new_from_slice(self.key.as_bytes()).unwrap();
        mac.update(self.message.as_bytes());
        format!("{:x}", mac.finalize().into_bytes())
    }
}

struct CipherSimulator {
    data: String,
}

impl CipherSimulator {
    fn new(data: String) -> Self {
        CipherSimulator { data }
    }

    fn xor_cipher(&self, key: &str) -> String {
        self.data.chars()
            .zip(key.chars())
            .map(|(x, y)| (x as u8 ^ y as u8) as char)
            .collect()
    }

    fn shift_cipher(&self, shift: u8) -> String {
        self.data.chars()
            .map(|x| ((x as u8 + shift) % 256) as char)
            .collect()
    }
}

struct DataProcessor {
    hash_simulator: HashSimulator,
    cipher_simulator: CipherSimulator,
}

impl DataProcessor {
    fn new(hash_simulator: HashSimulator, cipher_simulator: CipherSimulator) -> Self {
        DataProcessor {
            hash_simulator,
            cipher_simulator,
        }
    }

    fn process_data(&self) -> (String, String, String) {
        let hash_result = self.hash_simulator.hash_message();
        let hmac_result = self.hash_simulator.hmac_message();
        let xor_result = self.cipher_simulator.xor_cipher(&hash_result[..16]);
        let shift_result = self.cipher_simulator.shift_cipher(5);
        (hmac_result, xor_result, shift_result)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let key: String = (0..32).map(|_| format!("{:02x}", rng.gen::<u8>())).collect();
    let message = "SecureMessage".to_string();
    let hash_sim = HashSimulator::new(key.clone(), message.clone());
    let cipher_sim = CipherSimulator::new(message);
    let data_processor = DataProcessor::new(hash_sim, cipher_sim);
    let result = data_processor.process_data();
    println!("{:?}", result);
}