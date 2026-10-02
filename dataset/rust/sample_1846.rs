use sha2::{Sha256, Digest};

fn process_data(data: &[u8], rounds: usize) -> Vec<u8> {
    let mut result = data.to_vec();
    for _ in 0..rounds {
        let mut hasher = Sha256::new();
        hasher.update(&result);
        result = hasher.finalize().to_vec();
    }
    result
}

fn main() {
    let data = b"initial_data";
    let final_result = process_data(data, 10);
    println!("{:x?}", final_result);
}