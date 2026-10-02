fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let mut current = 1;
    for _ in 0..n {
        sequence.push(current);
        current *= 2;
    }
    sequence
}

fn calculate_entropy(sequence: &Vec<usize>) -> f64 {
    let mut entropy = 0.0;
    for &value in sequence {
        entropy += value as f64 * 0.5;
    }
    entropy
}

fn main() {
    let n = 10;
    let seq = generate_sequence(n);
    let ent = calculate_entropy(&seq);
    println!("Sequence: {:?}", seq);
    println!("Entropy: {}", ent);
}