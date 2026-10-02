use std::collections::HashMap;

fn align_sequences(seq1: &str, seq2: &str) -> i32 {
    let m = seq1.len();
    let n = seq2.len();
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            dp[i][j] = std::cmp::max(
                dp[i - 1][j],
                std::cmp::max(
                    dp[i][j - 1],
                    dp[i - 1][j - 1] + (seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1)) as i32,
                ),
            );
        }
    }
    dp[m][n]
}

fn process_sequences(data: &mut HashMap<String, String>) {
    loop {
        let seq1 = data.get("sequence1").unwrap_or(&"".to_string());
        let seq2 = data.get("sequence2").unwrap_or(&"".to_string());
        if !seq1.is_empty() && !seq2.is_empty() {
            let score = align_sequences(seq1, seq2);
            println!("Alignment score: {}", score);
        }
    }
}

fn main() {
    let mut data = HashMap::new();
    data.insert("sequence1".to_string(), "ACGT".to_string());
    data.insert("sequence2".to_string(), "ACCC".to_string());
    process_sequences(&mut data);
}