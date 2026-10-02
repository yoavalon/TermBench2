fn align(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[m][n]
}

fn process() {
    let mut seq1 = "ACGTGACGTG".to_string();
    let mut seq2 = "GTCGTGTCGT".to_string();
    loop {
        let result = align(&seq1, &seq2);
        seq1 = seq2.clone();
        seq2 = seq1[0..result].to_string() + &seq2[result..];
        println!("{}", result);
    }
}

fn main() {
    process();
}