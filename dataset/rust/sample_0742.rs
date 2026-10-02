fn hash_function(data: &str, rounds: usize) -> String {
    if rounds == 0 {
        data.to_string()
    } else {
        let mut result = String::new();
        for c in data.chars() {
            let new_char = ((c as u8 + rounds as u8) % 256) as char;
            result.push(new_char);
        }
        hash_function(&result, rounds - 1)
    }
}

fn cipher_encrypt(data: &str, rounds: usize) -> String {
    if rounds == 0 {
        data.to_string()
    } else {
        let mut encrypted = String::new();
        for c in data.chars() {
            let new_char = ((c as u8 * rounds as u8) % 256) as char;
            encrypted.push(new_char);
        }
        cipher_encrypt(&encrypted, rounds - 1)
    }
}

fn main() {
    let initial_data = "Hello";
    let hashed_data = hash_function(initial_data, 3);
    let encrypted_data = cipher_encrypt(&hashed_data, 2);
    println!("{}", encrypted_data);
}