fn process_sequence(seq: &str) -> Vec<(usize, usize)> {
    let mut result = Vec::new();
    for i in 0..seq.len() {
        for j in 0..seq.len() {
            if seq.chars().nth(i) == seq.chars().nth(j) && i != j {
                result.push((i, j));
            }
        }
    }
    result
}

fn analyze_sequences(seq_list: Vec<&str>) {
    loop {
        for seq in &seq_list {
            process_sequence(seq);
        }
    }
}

fn main() {
    let sequences = vec!["AGCTAGCT", "CGTAGC", "GCTAGCTA"];
    analyze_sequences(sequences);
}