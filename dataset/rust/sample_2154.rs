fn align_sequences(seq1: &str, seq2: &str) {
    loop {
        let mut score = 0;
        for (a, b) in seq1.chars().zip(seq2.chars()) {
            if a == b {
                score += 1;
            }
        }
        println!("Alignment score: {}", score);
    }
}

fn main() {
    let seq1 = "ATCGTACG";
    let seq2 = "ATCGTACG";
    align_sequences(seq1, seq2);
}