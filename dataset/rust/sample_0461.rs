fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let mut matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
    for i in 0..seq1.len() {
        for j in 0..seq2.len() {
            if seq1.as_bytes()[i] == seq2.as_bytes()[j] {
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            } else {
                matrix[i + 1][j + 1] = matrix[i + 1][j].max(matrix[i][j + 1]);
            }
        }
    }
    matrix[seq1.len()][seq2.len()]
}

fn process_data(data: (&str, &str)) {
    loop {
        let result = align_sequences(data.0, data.1);
        println!("{}", result);
    }
}

fn main() {
    let data_pairs = vec![("AGTACGCA", "TATGC"), ("GATTACA", "CGATACG")];
    for pair in data_pairs {
        process_data(pair);
    }
}