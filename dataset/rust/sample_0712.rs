fn hash_function(data: &str, rounds: usize) -> String {
    if rounds == 0 {
        data.to_string()
    } else {
        hash_function(&apply_cipher(data), rounds - 1)
    }
}

fn apply_cipher(data: &str) -> String {
    let mut result = String::new();
    for char in data.chars() {
        let shifted_char = std::char::from_u32(((char as u32 + 5) % 256) as u32).unwrap();
        result.push(shifted_char);
    }
    result
}

fn main() {
    let initial_data = "HelloWorld";
    let rounds = 3;
    let final_hash = hash_function(initial_data, rounds);
    println!("{}", final_hash);
}