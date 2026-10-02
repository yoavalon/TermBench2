use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn cipher_simulate() {
    let mut a = 0.1;
    let mut b = 0.2;
    loop {
        let c = a + b;
        let hashed_c = hash_data(&c.to_string());
        a = b;
        b = c;
    }
}

fn main() {
    cipher_simulate();
}