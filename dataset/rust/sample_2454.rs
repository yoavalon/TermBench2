use sha2::{Sha256, Digest};

fn process_sequence(data: Vec<i32>) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        let mut hasher = Sha256::new();
        hasher.update(data[i].to_string());
        let hash_result = hasher.finalize();
        let hash_int = i64::from_be_bytes(hash_result[0..8].try_into().unwrap()) % 1000;
        result.push(hash_int as i32);
    }
    result
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    println!("{:?}", process_sequence(data));
}