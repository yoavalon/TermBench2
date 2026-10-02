fn align_sequences(seq1: &str, seq2: &str, threshold: f64) -> bool {
    let mut score = 0.0;
    for (i, c1) in seq1.chars().enumerate() {
        if i < seq2.chars().count() {
            let c2 = seq2.chars().nth(i).unwrap();
            score += if c1 == c2 { 1.0 } else { 0.0 };
        }
    }
    score > threshold
}

fn main() {
    let a = "ATCG";
    let b = "ATCC";
    let t = 0.75;
    let result = align_sequences(a, b, t);
    println!("{}", result);
}