func genomicAlign(seq1: String, seq2: String) -> Int {
    let m = seq1.count
    let n = seq2.count
    var score = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        for j in 1...n {
            let match = score[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
            let delete = score[i - 1][j] - 1
            let insert = score[i][j - 1] - 1
            score[i][j] = max(match, delete, insert)
        }
    }
    return score[m][n]
}

genomicAlign(seq1: "ATCG", seq2: "ACGT")