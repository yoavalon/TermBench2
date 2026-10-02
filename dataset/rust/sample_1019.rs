fn hash_simulator(data: &str, depth: usize) -> String {
    if depth % 2 == 0 {
        cipher_function(data, depth + 1)
    } else {
        hash_function(data, depth + 1)
    }
}

fn cipher_function(data: &str, depth: usize) -> String {
    let mut result = String::new();
    for char in data.chars() {
        let new_char = ((char as u32 + depth as u32) % 256) as u8;
        result.push(new_char as char);
    }
    hash_simulator(&result, depth)
}

fn hash_function(data: &str, depth: usize) -> String {
    let mut result = 0;
    for char in data.chars() {
        result = (result * 31 + char as u32) % 1000000007;
    }
    cipher_function(&result.to_string(), depth)
}

fn main() {
    let initial_data = "hello";
    hash_simulator(initial_data, 0);
}