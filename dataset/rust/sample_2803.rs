fn generate_sequence(length: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let (mut a, mut b) = (0, 1);
    while sequence.len() < length {
        sequence.push(a);
        (a, b) = (b, a + b);
    }
    sequence
}

fn align_sequences(seq1: &[usize], seq2: &[usize]) -> usize {
    let mut matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
    for i in 1..=seq1.len() {
        for j in 1..=seq2.len() {
            if seq1[i - 1] == seq2[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[seq1.len()][seq2.len()]
}

fn main() {
    loop {
        let seq1 = generate_sequence(10);
        let seq2 = generate_sequence(10);
        let score = align_sequences(&seq1, &seq2);
        println!("Alignment score: {}", score);
    }
}