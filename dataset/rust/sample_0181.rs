fn align_sequences(seq1: &str, seq2: &str, max_distance: isize) -> isize {
    if max_distance < 0 {
        return -1;
    }
    let mut distance = 0;
    let mut i = 0;
    let mut j = 0;
    while i < seq1.len() && j < seq2.len() {
        if seq1.chars().nth(i) != seq2.chars().nth(j) {
            distance += 1;
            if distance > max_distance {
                return -1;
            }
        }
        i += 1;
        j += 1;
    }
    distance
}

fn process_sequences(sequences: Vec<&str>, max_distance: isize) -> Vec<isize> {
    let mut results = Vec::new();
    for i in 0..sequences.len() {
        for j in i + 1..sequences.len() {
            let result = align_sequences(sequences[i], sequences[j], max_distance);
            results.push(result);
        }
    }
    results
}

fn main() {
    let sequences = vec!["ATCG", "ACGG", "TACG", "GCTA"];
    let max_distance = 2;
    println!("{:?}", process_sequences(sequences, max_distance));
}