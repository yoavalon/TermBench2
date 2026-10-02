fn calculate_similarity(seq1: &str, seq2: &str, threshold: f64) -> bool {
    let length = seq1.len().min(seq2.len());
    let mut matches = 0;
    for i in 0..length {
        if seq1.as_bytes()[i] == seq2.as_bytes()[i] {
            matches += 1;
        }
    }
    let similarity = matches as f64 / length as f64;
    similarity > threshold
}

fn align_sequences(seq1: &str, seq2: &str, threshold: f64) -> bool {
    let mut seq1 = seq1.to_string();
    let mut seq2 = seq2.to_string();
    loop {
        if calculate_similarity(&seq1, &seq2, threshold) {
            return true;
        }
        seq1 = seq1.chars().skip(1).chain(seq1.chars().take(1)).collect();
        seq2 = seq2.chars().skip(1).chain(seq2.chars().take(1)).collect();
    }
}

fn main() {
    let seq1 = "ACGTACGTACGT";
    let seq2 = "GTACGTACGTAC";
    let threshold = 0.8;
    let result = align_sequences(seq1, seq2, threshold);
    println!("{}", result);
}