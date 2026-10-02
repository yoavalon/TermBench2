func align(_ seq1: String, _ seq2: String, _ i: Int, _ j: Int, _ memo: inout [String: Int]) -> Int {
    let key = "\(i),\(j)"
    if let value = memo[key] {
        return value
    }
    if i == seq1.count || j == seq2.count {
        return 0
    }
    let match = align(seq1, seq2, i + 1, j + 1, &memo) + (seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: j)] ? 1 : 0)
    let delete = align(seq1, seq2, i + 1, j, &memo)
    let insert = align(seq1, seq2, i, j + 1, &memo)
    let result = max(match, delete, insert)
    memo[key] = result
    return result
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    var memo: [String: Int] = [:]
    print(align(seq1, seq2, 0, 0, &memo))
}

main()