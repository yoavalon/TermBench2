func align_sequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var dp = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            dp[i][j] = max(dp[i - 1][j - 1] + (char1 == char2 ? 1 : 0), dp[i - 1][j], dp[i][j - 1])
        }
    }
    return dp[len1][len2]
}

func process_data(data: (String, String)) -> Int {
    let seq1 = data.0
    let seq2 = data.1
    return align_sequences(seq1: seq1, seq2: seq2)
}

func main() {
    let data = ("AGGTAB", "GXTXAYB")
    print(process_data(data: data))
}

main()