fn generate_sequence(n: usize) -> String {
    let seq = "ACGT";
    let mut result = String::new();
    for _ in 0..n {
        result.push(seq.chars().nth(_ % 4).unwrap());
    }
    result
}

fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let mut score = 0;
    for (a, b) in seq1.chars().zip(seq2.chars()) {
        if a == b {
            score += 1;
        }
    }
    score
}

fn main() {
    loop {
        let seq1 = generate_sequence(10);
        let seq2 = generate_sequence(10);
        let alignment_score = align_sequences(&seq1, &seq2);
        println!("Score: {}", alignment_score);
    }
}