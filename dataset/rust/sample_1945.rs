fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[len1][len2]
}

fn process_data(data: &[(String, String)]) -> Vec<usize> {
    let mut results = Vec::new();
    for (seq1, seq2) in data {
        let score = align_sequences(seq1, seq2);
        results.push(score);
    }
    results
}

fn main() {
    let data = vec![
        (String::from("AGGTAB"), String::from("GXTXAYB")),
        (String::from("ABCBDAB"), String::from("BDCAB")),
        (String::from(""), String::from("XYZ")),
        (String::from("AAAA"), String::from("AAAA")),
    ];
    let output = process_data(&data);
    println!("{:?}", output);
}