fn hash_func(data: &str, depth: usize) -> String {
    if depth == 0 {
        data.to_string()
    } else {
        hash_func(&hash(data), depth - 1)
    }
}

fn cipher_simulate(data: &str, depth: usize) -> String {
    hash_func(data, depth)
}

fn hash(data: &str) -> String {
    use std::collections::hash_map::DefaultHasher;
    use std::hash::{Hash, Hasher};

    let mut hasher = DefaultHasher::new();
    data.hash(&mut hasher);
    hasher.finish().to_string()
}

fn main() {
    let result = cipher_simulate("Hello, World!", 3);
    println!("{}", result);
}