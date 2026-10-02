use sha2::{Sha256, Digest};

fn generate_sequence(seed: u64, length: usize) -> Vec<u64> {
    let mut sequence = Vec::new();
    let mut current = seed;
    for _ in 0..length {
        let mut hasher = Sha256::new();
        hasher.update(current.to_string());
        let hash_result = hasher.finalize();
        current = u64::from_be_bytes(hash_result[..8].try_into().unwrap());
        sequence.push(current);
    }
    sequence
}

fn analyze_sequence(sequence: Vec<u64>) -> std::collections::HashMap<u64, usize> {
    let mut stats = std::collections::HashMap::new();
    for &num in &sequence {
        *stats.entry(num).or_insert(0) += 1;
    }
    stats
}

fn main() {
    let seed = 42;
    let length = 10;
    let seq = generate_sequence(seed, length);
    let stats = analyze_sequence(seq);
    println!("{:?}", stats);
}