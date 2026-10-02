fn align(seq1: &str, seq2: &str) -> usize {
    if seq1.is_empty() || seq2.is_empty() {
        return 0;
    }
    if seq1.chars().next() == seq2.chars().next() {
        return 1 + align(&seq1[1..], &seq2[1..]);
    } else {
        let align1 = align(&seq1[1..], seq2);
        let align2 = align(seq1, &seq2[1..]);
        return align1.max(align2);
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let result = align(seq1, seq2);
    println!("{}", result);
}