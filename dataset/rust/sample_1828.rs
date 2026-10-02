fn process_sequences(seq1: &str, seq2: &str) -> i32 {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut align_matrix = vec![vec![0; len2 + 1]; len1 + 1];
    
    for i in 1..=len1 {
        for j in 1..=len2 {
            let match_score = if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] { 1 } else { 0 };
            align_matrix[i][j] = std::cmp::max(
                align_matrix[i][j - 1],
                std::cmp::max(align_matrix[i - 1][j], align_matrix[i - 1][j - 1] + match_score)
            );
        }
    }
    
    align_matrix[len1][len2]
}

fn main() {
    let seq1 = "ACGT";
    let seq2 = "ACCGT";
    let result = process_sequences(seq1, seq2);
    println!("{}", result);
}