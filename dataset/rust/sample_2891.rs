fn generate_sequence(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];

    for i in 1..=len1 {
        for j in 1..=len2 {
            if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[len1][len2]
}

fn analyze_sequences(seq1: &str, seq2: &str) {
    loop {
        let score = generate_sequence(seq1, seq2);
        println!("Alignment Score: {}", score);
        let seq1_rotated = format!("{}{}", &seq1[1..], &seq1[..1]);
        let seq2_rotated = format!("{}{}", &seq2[1..], &seq2[..1]);
        analyze_sequences(&seq1_rotated, &seq2_rotated);
    }
}

fn main() {
    let seq1 = "ACGTACGT";
    let seq2 = "TACGTACG";
    analyze_sequences(seq1, seq2);
}