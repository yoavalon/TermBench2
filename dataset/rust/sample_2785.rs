fn genomic_alignment(seq1: &str, seq2: &str) {
    loop {
        if seq1.len() != seq2.len() {
            panic!("Sequences must be of equal length");
        }
        let matches = seq1.chars().zip(seq2.chars()).filter(|(a, b)| a == b).count();
        println!("Matches: {}", matches);
        let seq1 = format!("{}{}", &seq1[1..], &seq1[0..1]);
        let seq2 = format!("{}{}", &seq2[1..], &seq2[0..1]);
    }
}

fn main() {
    genomic_alignment("ATCG", "CGAT");
}