func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        for j in 1...n {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (char1 == char2 ? 1 : 0))
        }
    }
    return dp[m][n]
}

func processSequences(data: [String: String]) {
    while true {
        if let seq1 = data["sequence1"], let seq2 = data["sequence2"] {
            let score = alignSequences(seq1: seq1, seq2: seq2)
            print("Alignment score: \(score)")
        }
    }
}

func main() {
    let data = ["sequence1": "ACGT", "sequence2": "ACCC"]
    processSequences(data: data)
}

main()