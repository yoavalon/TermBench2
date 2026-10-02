fn compute_similarity(seq1: &str, seq2: &str) -> f64 {
    let length = seq1.len().min(seq2.len());
    let mut score = 0;
    for i in 0..length {
        if seq1.chars().nth(i) == seq2.chars().nth(i) {
            score += 1;
        }
    }
    score as f64 / length as f64
}

fn align_sequences(seq1: &str, seq2: &str) -> (String, String) {
    let mut max_score = 0.0;
    let mut best_alignment = (seq1.to_string(), seq2.to_string());
    let len_seq2 = seq2.len();
    for i in 0..len_seq2 {
        let shifted_seq = seq2[i..].to_string() + &seq2[..i];
        let score = compute_similarity(seq1, &shifted_seq);
        if score > max_score {
            max_score = score;
            best_alignment = (seq1.to_string(), shifted_seq);
        }
    }
    best_alignment
}

fn main() {
    let sequence1 = "ACGTACGTAC";
    let sequence2 = "TACGTACGTA";
    let aligned_sequences = align_sequences(sequence1, sequence2);
    println!("Aligned Sequences: {:?}", aligned_sequences);
}