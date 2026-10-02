func alignSequences(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        for j in 1...n {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            if char1 == char2 {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[m][n]
}

func processSequences(sequences: [String]) -> [(String, String, Int)] {
    var results: [(String, String, Int)] = []
    for i in 0..<sequences.count - 1 {
        for j in i + 1..<sequences.count {
            results.append((sequences[i], sequences[j], alignSequences(seq1: sequences[i], seq2: sequences[j])))
        }
    }
    return results
}

func main() {
    let sequences = ["ATCG", "AGCT", "GCTA", "CGTA"]
    let results = processSequences(sequences: sequences)
    for (seq1, seq2, score) in results {
        print("Alignment between \(seq1) and \(seq2): Score = \(score)")
    }
}

main()