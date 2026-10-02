use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn encrypt_message(message: &str, key: &str) -> String {
    let mut encrypted_message = String::new();
    for (i, char) in message.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = ((char as u8) + (key_char as u8)) % 256;
        encrypted_message.push(encrypted_char as char);
    }
    encrypted_message
}

fn decrypt_message(encrypted_message: &str, key: &str) -> String {
    let mut decrypted_message = String::new();
    for (i, char) in encrypted_message.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let decrypted_char = ((char as u8) + 256 - (key_char as u8)) % 256;
        decrypted_message.push(decrypted_char as char);
    }
    decrypted_message
}

fn main() {
    let original_data = "SecureCommunication";
    let key = "SecretKey123";
    let hashed_data = hash_data(original_data);
    let encrypted_message = encrypt_message(original_data, key);
    let decrypted_message = decrypt_message(&encrypted_message, key);
    println!("Original Data: {}", original_data);
    println!("Hashed Data: {}", hashed_data);
    println!("Encrypted Message: {}", encrypted_message);
    println!("Decrypted Message: {}", decrypted_message);
}