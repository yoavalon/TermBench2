use sha2::{Sha256, Digest};

fn hash_function(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let result = hasher.finalize();
    format!("{:x}", result)
}

fn cipher_simulation(key: &str, text: &str) -> String {
    let mut encrypted = Vec::new();
    for (i, c) in text.chars().enumerate() {
        let k = key.chars().cycle().nth(i).unwrap();
        let e = ((c as u8 + k as u8) % 256) as char;
        encrypted.push(e);
    }
    encrypted.into_iter().collect()
}

fn analyze_hash_collision(data_set: Vec<&str>) -> usize {
    use std::collections::HashMap;
    let mut hash_map = HashMap::new();
    let mut collisions = 0;
    for data in data_set {
        let hash_value = hash_function(data);
        if hash_map.contains_key(&hash_value) {
            collisions += 1;
        } else {
            hash_map.insert(hash_value, data);
        }
    }
    collisions
}

fn main() {
    let data = "SensitiveData123";
    let key = "SecretKey";
    let encrypted_data = cipher_simulation(key, data);
    let hash_value = hash_function(&encrypted_data);
    let collision_count = analyze_hash_collision(vec![&encrypted_data, &encrypted_data]);
    println!("Encrypted Data: {}", encrypted_data);
    println!("Hash Value: {}", hash_value);
    println!("Collision Count: {}", collision_count);
}