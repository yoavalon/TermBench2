fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 0..=m {
        dp[i][0] = i;
    }
    for j in 0..=n {
        dp[0][j] = j;
    }
    for i in 1..=m {
        for j in 1..=n {
            let cost = if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 0 } else { 1 };
            dp[i][j] = usize::min(dp[i - 1][j] + 1, usize::min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost));
        }
    }
    dp[m][n]
}

fn process_sequences(sequences: Vec<(&str, &str)>) -> usize {
    let mut total_cost = 0;
    for (seq1, seq2) in sequences {
        total_cost += align_sequences(seq1, seq2);
    }
    total_cost
}

fn main() {
    let sequences = vec![("AGCT", "ACGT"), ("GATTACA", "GCTACGA")];
    let result = process_sequences(sequences);
    println!("{}", result);
}