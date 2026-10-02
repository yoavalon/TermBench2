fn align_sequences(seq1: &str, seq2: &str, max_len: usize) -> usize {
    let mut i = 0;
    let mut j = 0;
    let mut score = 0;
    while i < seq1.len() && j < seq2.len() && (i + j < max_len) {
        if seq1.chars().nth(i) == seq2.chars().nth(j) {
            score += 1;
        }
        i += 1;
        j += 1;
    }
    score
}

fn main() {
    let result = align_sequences("ACGT", "ACGG", 10);
    println!("{}", result);
}