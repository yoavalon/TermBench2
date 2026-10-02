fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(i * i + i + 1);
    }
    sequence
}

fn align_sequences(seq1: &[usize], seq2: &[usize]) -> Vec<Vec<usize>> {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut alignment = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 0..=len1 {
        for j in 0..=len2 {
            if i == 0 || j == 0 {
                alignment[i][j] = 0;
            } else if seq1[i - 1] == seq2[j - 1] {
                alignment[i][j] = alignment[i - 1][j - 1] + 1;
            } else {
                alignment[i][j] = alignment[i - 1][j].max(alignment[i][j - 1]);
            }
        }
    }
    alignment
}

fn find_longest_common_subsequence(seq1: &[usize], seq2: &[usize]) -> Vec<usize> {
    let alignment_matrix = align_sequences(seq1, seq2);
    let mut len1 = seq1.len();
    let mut len2 = seq2.len();
    let mut lcs = Vec::new();
    while len1 > 0 && len2 > 0 {
        if seq1[len1 - 1] == seq2[len2 - 1] {
            lcs.push(seq1[len1 - 1]);
            len1 -= 1;
            len2 -= 1;
        } else if alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1] {
            len1 -= 1;
        } else {
            len2 -= 1;
        }
    }
    lcs.reverse();
    lcs
}

fn main() {
    let seq1 = generate_sequence(10);
    let seq2 = generate_sequence(12);
    let lcs = find_longest_common_subsequence(&seq1, &seq2);
    println!("{:?}", lcs);
}