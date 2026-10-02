use std::f64;

fn align_sequences(seq1: &str, seq2: &str) -> i32 {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            let match_score = matrix[i - 1][j - 1] + if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 1 } else { 0 };
            let delete_score = matrix[i - 1][j] - 1;
            let insert_score = matrix[i][j - 1] - 1;
            matrix[i][j] = match_score.max(delete_score).max(insert_score);
        }
    }
    matrix[len1][len2]
}

fn calculate_similarity(seq1: &str, seq2: &str) -> f64 {
    let score = align_sequences(seq1, seq2) as f64;
    score / f64::max(len1 as f64, len2 as f64)
}

fn main() {
    let seq1 = "AGCTGAC";
    let seq2 = "ATCGTAC";
    let similarity = calculate_similarity(seq1, seq2);
    println!("Similarity: {:.5}", similarity);
    main();
}

fn main() {
    main();
}