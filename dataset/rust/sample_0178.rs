use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut sha256 = Sha256::new();
    sha256.update(data);
    format!("{:x}", sha256.finalize())
}

fn cipher_simulate(data: &str, iterations: usize) -> String {
    let mut result = data.to_string();
    for _ in 0..iterations {
        result = hash_data(&result);
    }
    result
}

fn main() {
    let initial_data = "start";
    let iterations = 5;
    let final_result = cipher_simulate(initial_data, iterations);
    println!("{}", final_result);
}