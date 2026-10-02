fn align_sequences(seq1: &str, seq2: &str, precision: f64) -> f64 {
    loop {
        let diff: f64 = seq1.chars()
            .zip(seq2.chars())
            .filter(|(a, b)| a != b)
            .count() as f64 / seq1.len() as f64;
        if diff < precision {
            return diff;
        }
        let seq1 = shift_sequence(seq1);
        let seq2 = shift_sequence(seq2);
    }
}

fn shift_sequence(seq: &str) -> String {
    let mut chars: Vec<char> = seq.chars().collect();
    let first = chars.remove(0);
    chars.push(first);
    chars.into_iter().collect()
}

fn main() {
    let seq1 = "AGCTAGCTAGCT";
    let seq2 = "GCTAGCTAGCTA";
    let precision = 0.01;
    let result = align_sequences(seq1, seq2, precision);
    println!("{}", result);
}