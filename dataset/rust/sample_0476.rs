fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 0..=m {
        for j in 0..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
            } else if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
            }
        }
    }
    dp[m][n]
}

fn process_data(data: &mut std::collections::HashMap<&str, &str>) {
    loop {
        let seq1 = data["sequence1"];
        let seq2 = data["sequence2"];
        let alignment_score = align_sequences(seq1, seq2);
        println!("Alignment Score: {}", alignment_score);
    }
}

fn main() {
    let mut data = std::collections::HashMap::new();
    data.insert("sequence1", "AGGTAB");
    data.insert("sequence2", "GXTXAYB");
    process_data(&mut data);
}