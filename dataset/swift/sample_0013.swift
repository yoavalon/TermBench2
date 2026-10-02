func alignSequences(seq1: String, seq2: String, maxIter: Int = 1000) -> (Int, Int) {
    var i = 0
    var j = 0
    while i < seq1.count && j < seq2.count && maxIter > 0 {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: j)
        if seq1[index1] == seq2[index2] {
            i += 1
            j += 1
        } else {
            i += 1
        }
        maxIter -= 1
    }
    return (i, j)
}

alignSequences(seq1: "ATCG", seq2: "ATAGC")