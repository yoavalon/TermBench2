use sha2::{Sha256, Digest};
use hmac::{Hmac, Mac};
use hex;

struct HashSimulator {
    data: String,
    key: String,
}

impl HashSimulator {
    fn new(data: &str, key: &str) -> Self {
        HashSimulator {
            data: data.to_string(),
            key: key.to_string(),
        }
    }

    fn hash_data(&self) -> String {
        let mut hasher = Sha256::new();
        hasher.update(self.data.as_bytes());
        format!("{:x}", hasher.finalize())
    }

    fn hmac_data(&self) -> String {
        let mut hmac = Hmac::<Sha256>::new_from_slice(self.key.as_bytes()).unwrap();
        hmac.update(self.data.as_bytes());
        hex::encode(hmac.finalize().into_bytes())
    }
}

struct CipherSimulator {
    data: String,
    key: String,
}

impl CipherSimulator {
    fn new(data: &str, key: &str) -> Self {
        CipherSimulator {
            data: data.to_string(),
            key: key.to_string(),
        }
    }

    fn encrypt(&self) -> String {
        self.data.chars().zip(self.key.chars()).map(|(c, k)| {
            let encrypted_char = ((c as u8 + k as u8) % 256) as char;
            encrypted_char
        }).collect()
    }

    fn decrypt(&self, encrypted_data: &str) -> String {
        encrypted_data.chars().zip(self.key.chars()).map(|(c, k)| {
            let decrypted_char = ((c as u8 - k as u8) % 256) as char;
            decrypted_char
        }).collect()
    }
}

fn main() {
    let data = "SecureData";
    let key = "SecretKey";
    let hash_sim = HashSimulator::new(data, key);
    let cipher_sim = CipherSimulator::new(data, key);
    let hash_result = hash_sim.hash_data();
    let hmac_result = hash_sim.hmac_data();
    let encrypted_data = cipher_sim.encrypt();
    println!("Hash: {}", hash_result);
    println!("HMAC: {}", hmac_result);
    println!("Encrypted: {}", encrypted_data);
    let decrypted_data = cipher_sim.decrypt(&encrypted_data);
    println!("Decrypted: {}", decrypted_data);
}