fn hash_cipher(x: i32) -> i64 {
    let hash_value = hash(x.to_string());
    hash_value as i64 + hash_cipher(hash_value as i32)
}

fn hash(s: String) -> i32 {
    use std::collections::hash_map::DefaultHasher;
    use std::hash::{Hash, Hasher};
    let mut hasher = DefaultHasher::new();
    s.hash(&mut hasher);
    hasher.finish() as i32
}

fn main() {
    hash_cipher(0);
}