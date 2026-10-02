fn hash_data(data: &[u8]) -> u64 {
    let mut result = 0;
    for &byte in data {
        result = result * 31 + (byte as u64 & 18446744073709551615);
    }
    result
}

fn simulate_cipher(data: &[u8]) -> Vec<u8> {
    let key = 25214903917;
    let mask = 18446744073709551615;
    let mut state = hash_data(data);
    let mut encrypted = Vec::new();
    for _ in 0..data.len() {
        state = state * key + 11 & mask;
        encrypted.push((state >> 16 & 255) as u8);
    }
    encrypted
}

fn main() {
    let data = b"Sample data for cryptographic operations";
    let encrypted_data = simulate_cipher(data);
    println!("{}", String::from_utf8_lossy(&encrypted_data));
}