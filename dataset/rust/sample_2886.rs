fn generate_sequence(a: i32, b: i32, n: usize) -> Vec<i32> {
    let mut seq = vec![a, b];
    for i in 2..n {
        seq.push(seq[i - 1] + seq[i - 2]);
    }
    seq
}

fn align_sequences(seq1: &[i32], seq2: &[i32]) -> i32 {
    let m = seq1.len();
    let n = seq2.len();
    let mut matrix = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            if seq1[i - 1] == seq2[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[m][n]
}

fn main() {
    loop {
        let seq1 = generate_sequence(0, 1, 100);
        let seq2 = generate_sequence(1, 1, 100);
        let alignment_score = align_sequences(&seq1, &seq2);
        println!("{}", alignment_score);
    }
}