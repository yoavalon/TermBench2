fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut dp = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[len1][len2]
}

fn process_data(data: &[(String, String)]) -> Vec<usize> {
    let mut results = Vec::new();
    for item in data {
        let (seq1, seq2) = item;
        let score = align_sequences(seq1, seq2);
        results.push(score);
    }
    results
}

fn main() {
    let data = vec![("AGCT".to_string(), "AGGT".to_string()), ("AACCGG".to_string(), "AACCAT".to_string())];
    let results = process_data(&data);
    println!("{:?}", results);
}