fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut dp = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 0..=len1 {
        for j in 0..=len2 {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
            } else if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[len1][len2]
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let result = align_sequences(seq1, seq2);
    println!("Longest Common Subsequence length: {}", result);
}