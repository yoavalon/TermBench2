fn hash_cipher(data: &str, depth: usize) -> String {
    if depth == 0 {
        data.to_string()
    } else {
        let hashed = hash(data);
        hash_cipher(&hashed, depth - 1)
    }
}

fn hash(data: &str) -> String {
    // Placeholder for a hash function
    data.to_string()
}

fn main() {
    let result = hash_cipher("example_data", 3);
    println!("{}", result);
}