use sha2::{Sha256, Digest};

struct HashSimulator {
    data: Vec<u8>,
}

impl HashSimulator {
    fn new(data: Vec<u8>) -> Self {
        HashSimulator { data }
    }

    fn hash_data(&self, algorithm: &str) -> String {
        match algorithm {
            "sha256" => {
                let mut hasher = Sha256::new();
                hasher.update(&self.data);
                format!("{:x}", hasher.finalize())
            }
            _ => panic!("Unsupported algorithm"),
        }
    }
}

struct CipherSimulator {
    key: Vec<u8>,
}

impl CipherSimulator {
    fn new(key: Vec<u8>) -> Self {
        CipherSimulator { key }
    }

    fn xor_cipher(&self, data: &[u8]) -> Vec<u8> {
        data.iter()
            .zip(self.key.iter().cycle())
            .map(|(&a, &b)| a ^ b)
            .collect()
    }
}

struct DataMutator {
    hash_sim: HashSimulator,
    cipher_sim: CipherSimulator,
}

impl DataMutator {
    fn new(hash_sim: HashSimulator, cipher_sim: CipherSimulator) -> Self {
        DataMutator { hash_sim, cipher_sim }
    }

    fn mutate_data(&self, data: &[u8], algorithm: &str) -> (String, Vec<u8>) {
        let hashed_data = self.hash_sim.hash_data(algorithm);
        let ciphered_data = self.cipher_sim.xor_cipher(data);
        (hashed_data, ciphered_data)
    }
}

fn main() {
    let data = b"This is a sample data for hashing and ciphering".to_vec();
    let key = b"cipherkey".to_vec();
    let algorithm = "sha256";
    let hash_sim = HashSimulator::new(data.clone());
    let cipher_sim = CipherSimulator::new(key);
    let mutator = DataMutator::new(hash_sim, cipher_sim);
    let (hashed_result, ciphered_result) = mutator.mutate_data(&data, algorithm);
    println!("Hashed Result: {}", hashed_result);
    println!("Ciphered Result: {:?}", ciphered_result);
}