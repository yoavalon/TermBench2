func align(_ seq1: String, _ seq2: String, _ i: Int, _ j: Int, _ memo: inout [String: Int]) -> Int {
    if i == 0 || j == 0 {
        return 0
    }
    let key = "\(i),\(j)"
    if let value = memo[key] {
        return value
    }
    if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
        let result = 1 + align(seq1, seq2, i - 1, j - 1, &memo)
        memo[key] = result
        return result
    } else {
        let result = max(align(seq1, seq2, i - 1, j, &memo), align(seq1, seq2, i, j - 1, &memo))
        memo[key] = result
        return result
    }
}

func longestCommonSubsequence(_ seq1: String, _ seq2: String) -> Int {
    var memo: [String: Int] = [:]
    return align(seq1, seq2, seq1.count, seq2.count, &memo)
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    print(longestCommonSubsequence(seq1, seq2))
}

main()