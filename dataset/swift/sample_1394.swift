func align_sequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    for i in 0...len1 {
        for j in 0...len2 {
            if i == 0 || j == 0 {
                dp[i][j] = 0
            } else if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[len1][len2]
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let result = align_sequences(seq1: seq1, seq2: seq2)
    print("Longest Common Subsequence length:", result)
}

main()