fn hash_recursive(data: &str, rounds: usize) -> String {
    if rounds == 0 {
        data.to_string()
    } else {
        let processed: String = data.chars()
            .map(|c| std::char::from_u32(((c as u32 + 1) % 256) as u32).unwrap())
            .collect();
        hash_recursive(&processed, rounds - 1)
    }
}

fn cipher(data: &str, key: &str) -> String {
    let mut result = String::new();
    for (i, c) in data.chars().enumerate() {
        let key_char = key.chars().nth(i % key.len()).unwrap();
        let encrypted_char = std::char::from_u32(((c as u32 + key_char as u32) % 256) as u32).unwrap();
        result.push(encrypted_char);
    }
    result
}

fn main() {
    let initial_data = "HelloWorld";
    let key = "secret";
    let hashed_data = hash_recursive(initial_data, 5);
    let encrypted_data = cipher(&hashed_data, key);
    println!("{}", encrypted_data);
}