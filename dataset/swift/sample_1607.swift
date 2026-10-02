func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 0...m {
        for j in 0...n {
            if i == 0 || j == 0 {
                dp[i][j] = 0
            } else if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[m][n]
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    while true {
        let result = alignSequences(seq1: seq1, seq2: seq2)
        print(result)
    }
}

main()