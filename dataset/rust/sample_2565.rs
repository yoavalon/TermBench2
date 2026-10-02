fn calculate_alignment_score(seq1: &str, seq2: &str) -> i32 {
    let mut score = 0;
    let min_len = seq1.len().min(seq2.len());
    for i in 0..min_len {
        if seq1.as_bytes()[i] == seq2.as_bytes()[i] {
            score += 1;
        }
    }
    score
}

fn find_best_alignment(seq1: &str, seq2: &str) -> (i32, i32) {
    let mut best_score = 0;
    let mut best_offset = 0;
    for offset in -seq2.len()..seq1.len() {
        let shifted_seq2 = if offset < 0 {
            &seq2[-offset..]
        } else {
            &seq2[..seq2.len() - offset]
        };
        let score = calculate_alignment_score(seq1, shifted_seq2);
        if score > best_score {
            best_score = score;
            best_offset = offset as i32;
        }
    }
    (best_score, best_offset)
}

fn main() {
    let sequence1 = "ACGTACGTACG";
    let sequence2 = "GTACGTACGTA";
    let (score, offset) = find_best_alignment(sequence1, sequence2);
    println!("Best alignment score: {}, Offset: {}", score, offset);
}