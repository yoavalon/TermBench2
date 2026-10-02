import Foundation

func align(seq1: String, seq2: String, i: Int, j: Int, memo: inout [String: Int]) -> Int {
    if i == 0 || j == 0 {
        return max(i, j)
    }
    let key = "\(i),\(j)"
    if let value = memo[key] {
        return value
    }
    if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
        memo[key] = align(seq1: seq1, seq2: seq2, i: i - 1, j: j - 1, memo: &memo)
    } else {
        memo[key] = 1 + min(align(seq1: seq1, seq2: seq2, i: i - 1, j: j, memo: &memo),
                          align(seq1: seq1, seq2: seq2, i: i, j: j - 1, memo: &memo),
                          align(seq1: seq1, seq2: seq2, i: i - 1, j: j - 1, memo: &memo))
    }
    return memo[key]!
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    var memo: [String: Int] = [:]
    print(align(seq1: seq1, seq2: seq2, i: seq1.count, j: seq2.count, memo: &memo))
}

main()