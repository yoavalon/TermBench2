fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 0..=len1 {
        matrix[i][0] = i;
    }
    for j in 0..=len2 {
        matrix[0][j] = j;
    }
    for i in 1..=len1 {
        for j in 1..=len2 {
            let cost = if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                0
            } else {
                1
            };
            matrix[i][j] = usize::min(
                matrix[i - 1][j] + 1,
                usize::min(matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost),
            );
        }
    }
    matrix[len1][len2]
}

fn main() {
    let sequence1 = "AGCTG";
    let sequence2 = "AGGCT";
    let distance = align_sequences(sequence1, sequence2);
    println!("Edit distance: {}", distance);
}