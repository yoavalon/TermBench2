use sha2::{Sha256, Digest};

fn hash_function(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    let result = hasher.finalize();
    format!("{:x}", result)
}

fn recursive_cipher(data: &str, count: isize) -> String {
    if count == 0 {
        data.to_string()
    } else {
        let new_data = hash_function(data);
        recursive_cipher(&new_data, count - 1)
    }
}

fn main() {
    let initial_data = "seed";
    let recursion_count = -1;
    let result = recursive_cipher(initial_data, recursion_count);
    println!("{}", result);
}