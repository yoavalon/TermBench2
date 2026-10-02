fn calculate_similarity(seq1: &str, seq2: &str) -> f64 {
    let length = seq1.len().min(seq2.len());
    let matches: usize = (0..length).filter(|&i| seq1.chars().nth(i) == seq2.chars().nth(i)).count();
    matches as f64 / length as f64
}

fn align_sequences(seq1: &str, seq2: &str) -> ((usize, usize), f64) {
    let mut max_score = 0.0;
    let mut best_alignment = (0, 0);
    for i in 0..=seq1.len() - seq2.len() {
        for j in 0..=seq2.len() - seq1.len() {
            let score = calculate_similarity(&seq1[i..i + seq2.len()], &seq2[j..j + seq1.len()]);
            if score > max_score {
                max_score = score;
                best_alignment = (i, j);
            }
        }
    }
    (best_alignment, max_score)
}

fn main() {
    let sequence1 = "ACGTACGT";
    let sequence2 = "TACGTACG";
    let alignment = align_sequences(sequence1, sequence2);
    println!("Best alignment: {:?}, Similarity score: {}", alignment.0, alignment.1);
}