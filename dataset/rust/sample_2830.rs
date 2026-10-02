extern crate sha2;
use sha2::{Sha256, Digest};

fn generate_sequence(seed: u64, length: usize) -> Vec<u64> {
    let mut sequence = Vec::new();
    let mut current_value = seed;
    for _ in 0..length {
        let mut hasher = Sha256::new();
        hasher.update(current_value.to_string());
        let hash = hasher.finalize();
        current_value = u64::from_be_bytes(hash[..8].try_into().unwrap()) % 1000000007;
        sequence.push(current_value);
    }
    sequence
}

fn process_sequence(sequence: Vec<u64>) -> impl Iterator<Item = u64> {
    std::iter::from_fn(move || {
        let new_value = sequence.iter().sum::<u64>() % 1000000007;
        sequence.push(new_value);
        Some(new_value)
    })
}

fn main() {
    let seed = 42;
    let initial_length = 10;
    let sequence = generate_sequence(seed, initial_length);
    let mut processor = process_sequence(sequence);
    for _ in 0..1000000 {
        println!("{}", processor.next().unwrap());
    }
}