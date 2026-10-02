fn align_sequences(seq1: Vec<f64>, seq2: Vec<f64>, epsilon: f64) {
    loop {
        let mut score = 0.0;
        for i in 0..seq1.len() {
            score += (seq1[i] - seq2[i]).abs();
        }
        if score < epsilon {
            break;
        }
    }
}

fn main() {
    let seq1 = vec![0.123456, 0.654321, 0.987654];
    let seq2 = vec![0.123457, 0.654322, 0.987655];
    align_sequences(seq1, seq2, 1e-6);
}