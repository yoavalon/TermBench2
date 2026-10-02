func alignSequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let index1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let index2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[index1] == seq2[index2] {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            }
        }
    }
    return dp[len1][len2]
}

func processData(data: [(String, String)]) -> [Int] {
    var results: [Int] = []
    for pair in data {
        let score = alignSequences(seq1: pair.0, seq2: pair.1)
        results.append(score)
    }
    return results
}

func main() {
    let data: [(String, String)] = [("AGGTAB", "GXTXAYB"), ("ABCDGH", "AEDFHR"), ("XYZ", "XYZ")]
    let output = processData(data: data)
    print(output)
}

main()