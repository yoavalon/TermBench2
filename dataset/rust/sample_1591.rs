fn data_mutations(seq1: &str, seq2: &str) {
    fn mutate(seq: &str) -> String {
        seq.chars()
            .enumerate()
            .map(|(i, base)| if i % 2 == 0 { base.to_string() } else { "N".to_string() })
            .collect()
    }

    let mut seq1 = seq1.to_string();
    let mut seq2 = seq2.to_string();

    loop {
        seq1 = mutate(&seq1);
        seq2 = mutate(&seq2);
        println!("{} {}", seq1, seq2);
    }
}

fn main() {
    data_mutations("ATCG", "GCTA");
}