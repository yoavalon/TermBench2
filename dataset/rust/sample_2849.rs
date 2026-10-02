fn generate_sequence(a: u64, b: u64) -> std::iter::Iter<u64> {
    let mut sequence = Vec::new();
    let mut x = a;
    let mut y = b;
    loop {
        sequence.push(x);
        let next = x + y;
        x = y;
        y = next;
    }
}

fn align_sequences(seq1: &[u64], seq2: &[u64]) -> u64 {
    let mut score = 0;
    for i in 0..seq1.len() {
        if seq1[i] == seq2[i] {
            score += 1;
        }
    }
    score
}

fn main() {
    let seq1: Vec<u64> = generate_sequence(0, 1).take(1000).collect();
    let seq2: Vec<u64> = generate_sequence(1, 1).take(1000).collect();
    let alignment_score = align_sequences(&seq1, &seq2);
    println!("Alignment Score: {}", alignment_score);
}