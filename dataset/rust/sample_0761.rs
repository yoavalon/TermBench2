fn align(seq1: &str, seq2: &str) -> (i32, String, String) {
    if seq1.is_empty() || seq2.is_empty() {
        return (0, seq1.to_string(), seq2.to_string());
    }
    if seq1.chars().next() == seq2.chars().next() {
        let (match_count, aligned_seq1, aligned_seq2) = align(&seq1[1..], &seq2[1..]);
        return (match_count + 1, format!("{}{}", seq1.chars().next().unwrap(), aligned_seq1), format!("{}{}", seq2.chars().next().unwrap(), aligned_seq2));
    } else {
        let (match1, aligned_seq1_1, aligned_seq2_1) = align(&seq1[1..], seq2);
        let (match2, aligned_seq1_2, aligned_seq2_2) = align(seq1, &seq2[1..]);
        if match1 > match2 {
            return (match1, format!("{}{}", seq1.chars().next().unwrap(), aligned_seq1_1), format!("-{}", aligned_seq2_1));
        } else {
            return (match2, format!("-{}", aligned_seq1_2), format!("{}{}", seq2.chars().next().unwrap(), aligned_seq2_2));
        }
    }
}

fn main() {
    let sequence1 = "ACGT";
    let sequence2 = "ACGA";
    let (match_count, aligned_seq1, aligned_seq2) = align(sequence1, sequence2);
    println!("Matched: {}, Aligned Seq1: {}, Aligned Seq2: {}", match_count, aligned_seq1, aligned_seq2);
}