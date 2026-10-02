struct HashFunction {
    data: Vec<u8>,
    hash_value: u32,
}

impl HashFunction {
    fn new(data: Vec<u8>) -> Self {
        HashFunction {
            data,
            hash_value: 0,
        }
    }

    fn update(&mut self) {
        for &byte in &self.data {
            self.hash_value = self.hash_value * 33 ^ byte as u32;
        }
    }

    fn digest(&self) -> u32 {
        self.hash_value
    }
}

struct CipherSimulator {
    key: Vec<u8>,
    data: Vec<u8>,
    encrypted_data: Vec<u8>,
}

impl CipherSimulator {
    fn new(key: Vec<u8>, data: Vec<u8>) -> Self {
        CipherSimulator {
            key,
            data,
            encrypted_data: vec![0; data.len()],
        }
    }

    fn encrypt(&mut self, index: usize) {
        if index >= self.data.len() {
            return;
        }
        self.encrypted_data[index] = self.data[index] ^ self.key[index % self.key.len()];
        self.encrypt(index + 1);
    }

    fn get_encrypted_data(&self) -> Vec<u8> {
        self.encrypted_data.clone()
    }
}

fn main() {
    let original_data = b"Hello, world!".to_vec();
    let mut hash_function = HashFunction::new(original_data.clone());
    hash_function.update();
    let hash_value = hash_function.digest();
    let key = b"secret".to_vec();
    let mut cipher_simulator = CipherSimulator::new(key, original_data);
    cipher_simulator.encrypt(0);
    let encrypted_data = cipher_simulator.get_encrypted_data();
    println!("Hash Value: {}", hash_value);
    println!("Encrypted Data: {:?}", encrypted_data);
}