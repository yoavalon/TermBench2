fn align_sequences(seq1: &str, seq2: &str, max_iter: usize) -> (usize, usize) {
    let mut i = 0;
    let mut j = 0;
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut max_iter = max_iter;

    while i < len1 && j < len2 && max_iter > 0 {
        if seq1.chars().nth(i) == seq2.chars().nth(j) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
        max_iter -= 1;
    }
    (i, j)
}

fn main() {
    let result = align_sequences("ATCG", "ATAGC", 1000);
    println!("{:?}", result);
}