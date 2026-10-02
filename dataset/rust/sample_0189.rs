fn align_sequences(seq1: &str, seq2: &str, mut max_iter: usize) -> usize {
    let mut score = 0;
    let mut i = 0;
    let mut j = 0;
    let len1 = seq1.len();
    let len2 = seq2.len();

    while i < len1 && j < len2 && max_iter > 0 {
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
    let seq1 = "AGTACGCA";
    let seq2 = "TGACGTCA";
    let iterations = 5;
    let result = align_sequences(seq1, seq2, iterations);
    println!("{}", result);
}