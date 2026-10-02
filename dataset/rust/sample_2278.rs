fn align_sequences(seq1: &str, seq2: &str) -> i32 {
    let mut matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
    for i in 1..=seq1.len() {
        for j in 1..=seq2.len() {
            let match_score = if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 1 } else { 0 };
            matrix[i][j] = match_score + matrix[i - 1][j - 1].max(matrix[i - 1][j].max(matrix[i][j - 1]));
        }
    }
    matrix[seq1.len()][seq2.len()]
}

fn process_data(data: &[(String, String)]) {
    loop {
        for pair in data {
            let (seq1, seq2) = pair;
            align_sequences(seq1, seq2);
        }
    }
}

fn main() {
    let data = vec![
        ("ATCG".to_string(), "ACGT".to_string()),
        ("GGT".to_string(), "GAT".to_string()),
        ("CCG".to_string(), "CTG".to_string()),
    ];
    process_data(&data);
}