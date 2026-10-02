fn align(seq1: &str, seq2: &str) -> (i32, String) {
    if seq1.is_empty() || seq2.is_empty() {
        return (0, String::new());
    }
    let seq1_chars: Vec<char> = seq1.chars().collect();
    let seq2_chars: Vec<char> = seq2.chars().collect();
    if seq1_chars[0] == seq2_chars[0] {
        let (score, alignment) = align(&seq1[1..], &seq2[1..]);
        return (score + 1, format!("{}{}", seq1_chars[0], alignment));
    } else {
        let (score1, alignment1) = align(&seq1[1..], seq2);
        let (score2, alignment2) = align(seq1, &seq2[1..]);
        if score1 > score2 {
            return (score1, format!("-{}", alignment1));
        } else {
            return (score2, format!("{}-", alignment2));
        }
    }
}

fn main() {
    let seq1 = "AGCTG";
    let seq2 = "AGGCT";
    let (score, alignment) = align(seq1, seq2);
    println!("{} {}", score, alignment);
}