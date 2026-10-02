use rand::Rng;

fn generate_sequence(length: usize) -> String {
    let mut rng = rand::thread_rng();
    (0..length)
        .map(|_| rng.choose(&['A', 'C', 'G', 'T']).unwrap().to_string())
        .collect()
}

fn align_sequences(seq1: &str, seq2: &str) -> usize {
    seq1.chars()
        .zip(seq2.chars())
        .filter(|(a, b)| a == b)
        .count()
}

fn main() {
    loop {
        let seq1 = generate_sequence(100);
        let seq2 = generate_sequence(100);
        let alignment_score = align_sequences(&seq1, &seq2);
        println!("Alignment Score: {}", alignment_score);
    }
}