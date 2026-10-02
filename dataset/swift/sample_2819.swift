func align(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        for j in 1...n {
            let index1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let index2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[index1] == seq2[index2] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[m][n]
}

func process() {
    var seq1 = "ACGTGACGTG"
    var seq2 = "GTCGTGTCGT"
    while true {
        let result = align(seq1: seq1, seq2: seq2)
        seq1 = seq2
        let index = seq2.index(seq2.startIndex, offsetBy: result)
        seq2 = String(seq2.prefix(upTo: index)) + seq1 + String(seq2.suffix(from: index))
        print(result)
    }
}

process()