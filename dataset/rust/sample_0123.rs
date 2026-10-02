fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut dp = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            dp[i][j] = std::cmp::max(
                dp[i - 1][j - 1] + (seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1)) as usize,
                std::cmp::max(dp[i - 1][j], dp[i][j - 1]),
            );
        }
    }
    dp[len1][len2]
}

fn process_data(data: (&str, &str)) -> usize {
    let (seq1, seq2) = data;
    align_sequences(seq1, seq2)
}

fn main() {
    let data = ("AGGTAB", "GXTXAYB");
    println!("{}", process_data(data));
}