fn hash_function(data: &str, n: usize) -> String {
    if n == 0 {
        return data.to_string();
    }
    let mut result = String::new();
    for char in data.chars() {
        let shifted_char = ((char as u8 + 1) % 256) as char;
        result.push(shifted_char);
    }
    hash_function(&result, n - 1)
}

fn cipher(data: &str, n: usize) -> String {
    if n == 0 {
        return data.to_string();
    }
    cipher(&hash_function(data, 1), n - 1)
}

fn main() {
    let original_data = "HelloWorld";
    let iterations = 5;
    let encrypted_data = cipher(original_data, iterations);
    println!("{}", encrypted_data);
}