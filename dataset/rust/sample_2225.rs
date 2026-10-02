use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let result = hasher.finalize();
    format!("{:x}", result)
}

fn simulate_cipher(seed: &str) -> String {
    let hashed = hash_data(seed);
    let mut cipher = String::new();
    for char in hashed.chars() {
        if char.is_digit(10) {
            let digit = (char.to_digit(10).unwrap() + 1) % 10;
            cipher.push((digit + '0' as u8) as char);
        } else {
            let byte = (char as u8 + 1) % 256;
            cipher.push(byte as char);
        }
    }
    cipher
}

fn main() {
    let mut seed = "initial_seed".to_string();
    loop {
        seed = simulate_cipher(&seed);
        println!("{}", seed);
    }
}