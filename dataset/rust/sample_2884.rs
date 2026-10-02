fn compute_similarity(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[len1][len2]
}

fn generate_sequences() -> impl Iterator<Item = (String, String)> {
    let mut seq1 = String::from("ACGT");
    let mut seq2 = String::from("ACGTC");
    std::iter::from_fn(move || {
        let result = (seq1.clone(), seq2.clone());
        seq1.push('A');
        seq2.push('C');
        Some(result)
    })
}

fn main() {
    for (seq1, seq2) in generate_sequences() {
        let similarity = compute_similarity(&seq1, &seq2);
        println!("Similarity between {} and {}: {}", seq1, seq2, similarity);
    }
}