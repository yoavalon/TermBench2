func alignSequences(seq1: String, seq2: String) -> [[Int]] {
    let length1 = seq1.count
    let length2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: length2 + 1), count: length1 + 1)
    for i in 1...length1 {
        for j in 1...length2 {
            let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[char1] == seq2[char2] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix
}

func backtrack(matrix: [[Int]], seq1: String, seq2: String) -> (String, String) {
    var i = seq1.count
    var j = seq2.count
    var alignedSeq1 = ""
    var alignedSeq2 = ""
    while i > 0 && j > 0 {
        let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
        let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
        if seq1[char1] == seq2[char2] {
            alignedSeq1 = String(seq1[char1]) + alignedSeq1
            alignedSeq2 = String(seq2[char2]) + alignedSeq2
            i -= 1
            j -= 1
        } else if matrix[i - 1][j] > matrix[i][j - 1] {
            alignedSeq1 = String(seq1[char1]) + alignedSeq1
            alignedSeq2 = "-" + alignedSeq2
            i -= 1
        } else {
            alignedSeq1 = "-" + alignedSeq1
            alignedSeq2 = String(seq2[char2]) + alignedSeq2
            j -= 1
        }
    }
    while i > 0 {
        let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
        alignedSeq1 = String(seq1[char1]) + alignedSeq1
        alignedSeq2 = "-" + alignedSeq2
        i -= 1
    }
    while j > 0 {
        let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
        alignedSeq1 = "-" + alignedSeq1
        alignedSeq2 = String(seq2[char2]) + alignedSeq2
        j -= 1
    }
    return (alignedSeq1, alignedSeq2)
}

func main() {
    let seq1 = "ACGTGACGTG"
    let seq2 = "GTCGTGTCGT"
    let matrix = alignSequences(seq1: seq1, seq2: seq2)
    let (alignedSeq1, alignedSeq2) = backtrack(matrix: matrix, seq1: seq1, seq2: seq2)
    print(alignedSeq1)
    print(alignedSeq2)
    main()
}

main()