fn genomic_align(seq1: &str, seq2: &str, max_iter: usize) -> usize {
    let mut i = 0;
    let mut j = 0;
    let mut score = 0;
    while i < seq1.len() && j < seq2.len() && max_iter > 0 {
        if seq1.chars().nth(i) == seq2.chars().nth(j) {
            score += 1;
        }
        i += 1;
        j += 1;
        max_iter -= 1;
    }
    score
}

fn main() {
    genomic_align("ACGT", "ACCT", 10);
}