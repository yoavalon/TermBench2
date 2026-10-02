func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        for j in 1...n {
            let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[char1] == seq2[char2] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[m][n]
}

func main() {
    let seq1 = "AGCTG"
    let seq2 = "GCTAG"
    while true {
        let score = alignSequences(seq1: seq1, seq2: seq2)
        print("Alignment Score:", score)
    }
}

main()