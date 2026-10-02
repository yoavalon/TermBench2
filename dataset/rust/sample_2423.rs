fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            dp[i][j] = std::cmp::max(dp[i - 1][j - 1] + (seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1)) as usize, 
                                      std::cmp::max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    dp[m][n]
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let result = align_sequences(seq1, seq2);
    println!("{}", result);
}