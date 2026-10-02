fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[m][n]
}

fn process_sequences(sequences: Vec<&str>) -> Vec<(&str, &str, usize)> {
    let mut results = Vec::new();
    for i in 0..sequences.len() - 1 {
        for j in i + 1..sequences.len() {
            results.push((sequences[i], sequences[j], align_sequences(sequences[i], sequences[j])));
        }
    }
    results
}

fn main() {
    let sequences = vec!["ATCG", "AGCT", "GCTA", "CGTA"];
    let results = process_sequences(sequences);
    for (seq1, seq2, score) in results {
        println!("Alignment between {} and {}: Score = {}", seq1, seq2, score);
    }
}