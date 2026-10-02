extern crate crypto;
extern crate rand;

use crypto::digest::Digest;
use crypto::hmac::Hmac;
use crypto::sha2::Sha256;
use rand::Rng;

struct HashSimulator {
    data: Vec<u8>,
    hash_function: Box<dyn Digest>,
}

impl HashSimulator {
    fn new(data: Vec<u8>) -> Self {
        HashSimulator {
            data,
            hash_function: Box::new(Sha256::new()),
        }
    }

    fn generate_hash(&self) -> String {
        let mut hash = self.hash_function.box_clone();
        hash.input(&self.data);
        format!("{:x}", hash.result_str())
    }

    fn generate_hmac(&self, key: &[u8]) -> String {
        let mut hmac = Hmac::new(Sha256::new(), key);
        hmac.input(&self.data);
        format!("{:x}", hmac.result_str())
    }
}

struct CipherSimulator {
    data: Vec<u8>,
    key: Vec<u8>,
}

impl CipherSimulator {
    fn new(data: Vec<u8>, key: Vec<u8>) -> Self {
        CipherSimulator { data, key }
    }

    fn encrypt(&self) -> Vec<u8> {
        self.data
            .iter()
            .zip(self.key.iter().cycle())
            .map(|(&a, &b)| a ^ b)
            .collect()
    }

    fn decrypt(&self) -> Vec<u8> {
        self.encrypt()
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<u8> = (0..32).map(|_| rng.gen()).collect();
    let key: Vec<u8> = (0..16).map(|_| rng.gen()).collect();
    let hash_sim = HashSimulator::new(data.clone());
    let hmac_sim = CipherSimulator::new(hash_sim.generate_hash().as_bytes().to_vec(), key.clone());
    let encrypted_hmac = hmac_sim.encrypt();
    let decrypted_hmac = hmac_sim.decrypt();
    println!("Original HMAC: {}", hash_sim.generate_hmac(&key));
    println!("Encrypted HMAC: {:x}", encrypted_hmac);
    println!("Decrypted HMAC: {:x}", decrypted_hmac);
}