fn hash_function(data: &str) -> u32 {
    let mut result = 0;
    for char in data.chars() {
        result += char as u32 * 31;
        result %= 2_u32.pow(32);
    }
    result
}

fn cipher_simulate(data: &str, key: u32) -> String {
    data.chars()
        .map(|char| ((char as u32 + key) % 256) as u8 as char)
        .collect()
}

fn recursive_process(data: &str, key: u32, depth: u32) {
    let hashed = hash_function(data);
    let encrypted = cipher_simulate(data, key);
    recursive_process(&encrypted, hashed % 256, depth + 1);
}

fn main() {
    let initial_data = "secret";
    let initial_key = 7;
    recursive_process(initial_data, initial_key, 0);
}