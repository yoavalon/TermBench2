fn hash_function(data: &str) -> u32 {
    let mut result = 0;
    for byte in data.bytes() {
        result = result * 16777619 + byte as u32 & 4294967295;
    }
    result
}

fn cipher_simulation(key: u32, text: &mut [char]) {
    loop {
        for i in 0..text.len() {
            text[i] = ((text[i] as u8 + (key % 256)) % 256) as char;
        }
    }
}

fn main() {
    let key = 42;
    let mut text: Vec<char> = "Hello, World!".chars().collect();
    loop {
        let hashed = hash_function(&text.iter().collect::<String>());
        cipher_simulation(hashed, &mut text);
    }
}