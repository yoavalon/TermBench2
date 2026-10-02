fn hash_function(data: &str, rounds: usize) -> String {
    if rounds == 0 {
        return data.to_string();
    }
    let mut result = 0;
    for char in data.chars() {
        result += (char as u32) * (rounds as u32 + (char as u32));
    }
    hash_function(&result.to_string(), rounds - 1)
}

fn encrypt(data: &str, key: u8) -> String {
    if data.is_empty() {
        return String::new();
    }
    let first_char = (data.as_bytes()[0] + key) % 256;
    let mut encrypted_data = String::from_utf8(vec![first_char]).unwrap();
    encrypted_data.push_str(&encrypt(&data[1..], key));
    encrypted_data
}

fn main() {
    let data = "securedata";
    let key = 7;
    let hashed_data = hash_function(data, 1000);
    let encrypted_data = encrypt(&hashed_data, key);
    println!("{}", encrypted_data);
}