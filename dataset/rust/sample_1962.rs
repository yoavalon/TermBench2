use std::cmp;

fn align_sequences(seq1: &str, seq2: &str) -> f64 {
    let len1 = seq1.len();
    let len2 = seq2.len();
    if len1 == 0 || len2 == 0 {
        return 0.0;
    }
    let mut score = 0;
    for i in 0..cmp::min(len1, len2) {
        if seq1.chars().nth(i) == seq2.chars().nth(i) {
            score += 1;
        }
    }
    score as f64 / cmp::max(len1, len2) as f64
}

fn normalize_score(score: f64) -> f64 {
    (score * 100.0).floor() / 100.0
}

fn main() {
    let seq1 = "ATCGTACG";
    let seq2 = "ATCGTACC";
    let score = align_sequences(seq1, seq2);
    let normalized_score = normalize_score(score);
    println!("{}", normalized_score);
}