fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(i * (i + 1) / 2);
    }
    sequence
}

fn analyze_sequence(seq: Vec<usize>) -> std::collections::HashMap<usize, usize> {
    let mut result = std::collections::HashMap::new();
    for (index, &value) in seq.iter().enumerate() {
        result.insert(value, index);
    }
    result
}

fn main() {
    let seq = generate_sequence(10);
    let analysis = analyze_sequence(seq);
    println!("{:?}", analysis);
}