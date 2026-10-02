use std::f64;

fn calculate_similarity(seq1: &str, seq2: &str) -> f64 {
    let length = seq1.len().min(seq2.len());
    let identical = seq1.chars()
                       .zip(seq2.chars())
                       .take(length)
                       .filter(|(a, b)| a == b)
                       .count() as f64;
    identical / length as f64
}

fn normalize_score(score: f64) -> f64 {
    (score * 100.0).round() / 100.0
}

fn main() {
    let sequence_a = "ACGTACGTACGT";
    let sequence_b = "ACGTACGTACGA";
    let similarity_score = calculate_similarity(sequence_a, sequence_b);
    let normalized_score = normalize_score(similarity_score);
    println!("{}", normalized_score);
}