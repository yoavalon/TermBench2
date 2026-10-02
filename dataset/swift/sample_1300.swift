func genomicAlign(seq1: String, seq2: String, maxIter: Int) -> Int {
    var i = 0, j = 0, score = 0
    while i < seq1.count && j < seq2.count && maxIter > 0 {
        if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: j)] {
            score += 1
        }
        i += 1
        j += 1
        maxIter -= 1
    }
    return score
}

if let _ = CommandLine.arguments.first {
    genomicAlign(seq1: "ACGT", seq2: "ACCT", maxIter: 10)
}