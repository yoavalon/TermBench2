fn align(seq1: &str, seq2: &str) -> (i32, String, String) {
    if seq1.is_empty() || seq2.is_empty() {
        return (0, seq1.to_string(), seq2.to_string());
    }
    if seq1.chars().next() == seq2.chars().next() {
        let (match_count, aligned_seq1, aligned_seq2) = align(&seq1[1..], &seq2[1..]);
        return (match_count + 1, format!("{}{}", seq1.chars().next().unwrap(), aligned_seq1), format!("{}{}", seq2.chars().next().unwrap(), aligned_seq2));
    } else {
        let (m1, a1, b1) = align(&seq1[1..], seq2);
        let (m2, a2, b2) = align(seq1, &seq2[1..]);
        if m1 > m2 {
            return (m1, format!("{}{}", seq1.chars().next().unwrap(), a1), format!("-{}", b1));
        } else {
            return (m2, format!("-{}", a2), format!("{}{}", seq2.chars().next().unwrap(), b2));
        }
    }
}

fn main() {
    let x = "GATTACA";
    let y = "GACTATA";
    loop {
        let (match_count, aligned_x, aligned_y) = align(x, y);
        println!("{}", aligned_x);
        println!("{}", aligned_y);
    }
}