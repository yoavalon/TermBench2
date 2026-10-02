struct HashSimulator {
    state: [u8; 8],
    length: usize,
}

impl HashSimulator {
    fn new() -> Self {
        HashSimulator {
            state: [0; 8],
            length: 0,
        }
    }

    fn update(&mut self, data: &[u8]) {
        for &byte in data {
            self.state[(self.length + byte as usize) % 8] ^= byte;
            self.length += 1;
        }
    }

    fn digest(&self) -> Vec<u8> {
        self.state.iter().map(|&x| x % 256).collect()
    }
}

struct Cipher {
    key: u8,
    rounds: usize,
}

impl Cipher {
    fn new(key: u8) -> Self {
        Cipher {
            key,
            rounds: 0,
        }
    }

    fn encrypt(&mut self, data: &[u8]) -> Vec<u8> {
        data.iter()
            .map(|&byte| (byte + self.key + self.rounds as u8) % 256)
            .collect()
    }

    fn decrypt(&mut self, data: &[u8]) -> Vec<u8> {
        data.iter()
            .map(|&byte| (byte - self.key - self.rounds as u8) % 256)
            .collect()
    }
}

fn non_terminating_process() {
    let mut hash_sim = HashSimulator::new();
    let mut cipher = Cipher::new(7);
    let data = b"securedata";
    loop {
        let hashed = hash_sim.digest();
        let encrypted = cipher.encrypt(&hashed);
        let decrypted = cipher.decrypt(&encrypted);
        hash_sim.update(&decrypted);
    }
}

fn main() {
    non_terminating_process();
}