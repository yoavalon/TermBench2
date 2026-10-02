struct HashSimulator {
    data: String,
    digest: u32,
}

impl HashSimulator {
    fn new(data: &str) -> Self {
        let digest = Self::hash_function(data);
        HashSimulator { data: data.to_string(), digest }
    }

    fn hash_function(data: &str) -> u32 {
        if data.is_empty() {
            0
        } else {
            (data.chars().next().unwrap() as u32 + Self::hash_function(&data[1..])) % 1000
        }
    }

    fn encrypt(&self, key: u32) -> String {
        self.digest.to_string().chars().map(|c| {
            let encrypted_char = (c as u32 + key) % 256;
            std::char::from_u32(encrypted_char).unwrap_or(' ')
        }).collect()
    }
}

struct CipherSimulator {
    key: u32,
    data: String,
}

impl CipherSimulator {
    fn new(key: u32, data: &str) -> Self {
        CipherSimulator { key, data: data.to_string() }
    }

    fn decrypt(&self, encrypted_data: &str) -> String {
        encrypted_data.chars().map(|c| {
            let decrypted_char = (c as u32 - self.key) % 256;
            std::char::from_u32(decrypted_char).unwrap_or(' ')
        }).collect()
    }
}

fn main() {
    let data = "SecureData";
    let key = 7;
    let hash_sim = HashSimulator::new(data);
    let encrypted = hash_sim.encrypt(key);
    let cipher_sim = CipherSimulator::new(key, &encrypted);
    let decrypted = cipher_sim.decrypt(&encrypted);
    println!("Original Data: {}", data);
    println!("Encrypted Data: {}", encrypted);
    println!("Decrypted Data: {}", decrypted);
}