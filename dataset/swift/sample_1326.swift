func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    let seq1Array = Array(seq1)
    let seq2Array = Array(seq2)
    
    for i in 1...m {
        for j in 1...n {
            if seq1Array[i - 1] == seq2Array[j - 1] {
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
    let result = alignSequences(seq1: seq1, seq2: seq2)
    print(result)
}

main()