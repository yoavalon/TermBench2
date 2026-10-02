fn hash_function(data: &str, depth: usize) -> String {
    if depth > 5 {
        return data.to_string();
    }
    let mut result = 0;
    for char in data.chars() {
        result = (result * 31 + char as u32) % 1000000;
    }
    hash_function(&result.to_string(), depth + 1)
}

fn cipher_simulate(text: &str, key: u8) -> String {
    let mut encrypted = String::new();
    for char in text.chars() {
        let shifted = (char as u8 + key) % 256;
        encrypted.push(shifted as char);
    }
    encrypted
}

fn main() {
    let data = "SecureData123";
    let hashed = hash_function(data, 1);
    let key = 7;
    let encrypted = cipher_simulate(&hashed, key);
    println!("{}", encrypted);
}