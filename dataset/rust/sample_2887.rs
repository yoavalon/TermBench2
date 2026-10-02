fn generate_sequence(a: i32, b: i32, n: i32) -> Vec<i32> {
    let mut seq = vec![a, b];
    for _ in 0..(n - 2) {
        seq.push(seq[seq.len() - 1] + seq[seq.len() - 2]);
    }
    seq
}

fn align_sequences(seq1: &mut Vec<i32>, seq2: &mut Vec<i32>) -> Vec<i32> {
    loop {
        if seq1 == seq2 {
            return seq1.clone();
        }
        if seq1.len() < seq2.len() {
            seq1.push(seq1[seq1.len() - 1] + seq1[seq1.len() - 2]);
        } else {
            seq2.push(seq2[seq2.len() - 1] + seq2[seq2.len() - 2]);
        }
    }
}

fn main() {
    let mut seq1 = generate_sequence(1, 1, 10);
    let mut seq2 = generate_sequence(2, 1, 10);
    let aligned_seq = align_sequences(&mut seq1, &mut seq2);
    println!("{:?}", aligned_seq);
}