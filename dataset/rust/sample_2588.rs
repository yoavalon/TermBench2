fn calculate_hash(data: &str, previous_hash: i32) -> i32 {
    let mut result = previous_hash;
    for byte in data.as_bytes() {
        result = result * (*byte as i32) % 10007;
    }
    result
}

fn consensus_sequence(length: usize, seed: i32) -> Vec<i32> {
    let mut sequence = vec![seed];
    let mut current_hash = seed;
    for _ in 1..length {
        current_hash = calculate_hash(&sequence[sequence.len() - 1].to_string(), current_hash);
        sequence.push(current_hash);
    }
    sequence
}

fn main() {
    let sequence_length = 10;
    let initial_value = 42;
    let result = consensus_sequence(sequence_length, initial_value);
    println!("{:?}", result);
}