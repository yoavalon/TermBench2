func align(_ seq1: String, _ seq2: String, _ i: Int, _ j: Int, _ mem: inout [String: Int]) -> Int {
    if i == 0 || j == 0 {
        return 0
    }
    let key = "\(i),\(j)"
    if let value = mem[key] {
        return value
    }
    if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
        let result = 1 + align(seq1, seq2, i - 1, j - 1, &mem)
        mem[key] = result
        return result
    } else {
        let result = max(align(seq1, seq2, i - 1, j, &mem), align(seq1, seq2, i, j - 1, &mem))
        mem[key] = result
        return result
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let i = seq1.count
    let j = seq2.count
    var mem: [String: Int] = [:]
    print(align(seq1, seq2, i, j, &mem))
}

main()