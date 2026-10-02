func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 0...m {
        dp[i][0] = i
    }
    for j in 0...n {
        dp[0][j] = j
    }
    
    for i in 1...m {
        for j in 1...n {
            let cost = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost)
        }
    }
    
    return dp[m][n]
}

func processSequences(sequences: [(String, String)]) -> Int {
    var totalCost = 0
    for (seq1, seq2) in sequences {
        totalCost += alignSequences(seq1: seq1, seq2: seq2)
    }
    return totalCost
}

func main() {
    let sequences = [("AGCT", "ACGT"), ("GATTACA", "GCTACGA")]
    let result = processSequences(sequences: sequences)
    print(result)
}

main()