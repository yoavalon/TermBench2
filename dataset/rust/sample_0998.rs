fn recursive_align(seq1: &str, seq2: &str, i: usize, j: usize) {
    if i < seq1.len() && j < seq2.len() {
        recursive_align(seq1, seq2, i + 1, j + 1);
    } else {
        recursive_align(seq1, seq2, i, j);
    }
}

fn main() {
    let seq1 = "ACGT";
    let seq2 = "ACGGT";
    recursive_align(seq1, seq2, 0, 0);
}