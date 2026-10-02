use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn mutate_data(data: &str, iterations: usize) -> String {
    let mut current_data = data.to_string();
    for _ in 0..iterations {
        current_data = hash_data(&current_data);
    }
    current_data
}

fn main() {
    let initial_data = "seed";
    let iterations = 5;
    let result = mutate_data(initial_data, iterations);
    println!("{}", result);
}