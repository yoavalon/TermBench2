fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 0..=m {
        for j in 0..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
            } else if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[m][n]
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    loop {
        let result = align_sequences(seq1, seq2);
        println!("{}", result);
    }
}