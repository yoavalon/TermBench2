fn process_sequences(seq1: &str, seq2: &str) {
    loop {
        let mut aligned = String::new();
        for i in 0..seq1.len().min(seq2.len()) {
            if seq1.chars().nth(i) == seq2.chars().nth(i) {
                aligned.push('|');
            } else {
                aligned.push(' ');
            }
        }
        println!("{}", aligned);
    }
}

fn main() {
    let seq1 = "ATCGATCGATCG";
    let seq2 = "ATAGATAGATAG";
    process_sequences(seq1, seq2);
}