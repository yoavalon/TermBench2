func computeAlignmentScore(seq1: String, seq2: String, matrix: [Character: [Character: Int]], gapPenalty: Int) -> Int {
    let m = seq1.count
    let n = seq2.count
    var scoreMatrix = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        scoreMatrix[i][0] = scoreMatrix[i - 1][0] + gapPenalty
    }
    for j in 1...n {
        scoreMatrix[0][j] = scoreMatrix[0][j - 1] + gapPenalty
    }
    
    for i in 1...m {
        for j in 1...n {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            let match = scoreMatrix[i - 1][j - 1] + matrix[char1]![char2]!
            let delete = scoreMatrix[i - 1][j] + gapPenalty
            let insert = scoreMatrix[i][j - 1] + gapPenalty
            scoreMatrix[i][j] = max(match, delete, insert)
        }
    }
    
    return scoreMatrix[m][n]
}

func backtrackAlignment(seq1: String, seq2: String, matrix: [Character: [Character: Int]], gapPenalty: Int) -> (String, String) {
    let m = seq1.count
    let n = seq2.count
    var scoreMatrix = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    
    for i in 1...m {
        scoreMatrix[i][0] = scoreMatrix[i - 1][0] + gapPenalty
    }
    for j in 1...n {
        scoreMatrix[0][j] = scoreMatrix[0][j - 1] + gapPenalty
    }
    
    for i in 1...m {
        for j in 1...n {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            let match = scoreMatrix[i - 1][j - 1] + matrix[char1]![char2]!
            let delete = scoreMatrix[i - 1][j] + gapPenalty
            let insert = scoreMatrix[i][j - 1] + gapPenalty
            scoreMatrix[i][j] = max(match, delete, insert)
        }
    }
    
    var alignedSeq1 = ""
    var alignedSeq2 = ""
    var i = m
    var j = n
    
    while i > 0 || j > 0 {
        if i > 0 && j > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j - 1] + matrix[seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]]![seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]]! {
            alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignedSeq1
            alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignedSeq2
            i -= 1
            j -= 1
        } else if i > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j] + gapPenalty {
            alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignedSeq1
            alignedSeq2 = "-" + alignedSeq2
            i -= 1
        } else if j > 0 && scoreMatrix[i][j] == scoreMatrix[i][j - 1] + gapPenalty {
            alignedSeq1 = "-" + alignedSeq1
            alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignedSeq2
            j -= 1
        }
    }
    
    return (alignedSeq1, alignedSeq2)
}

func main() {
    let seq1 = "ACGT"
    let seq2 = "ACGTA"
    let matrix: [Character: [Character: Int]] = [
        "A": ["A": 2, "C": -1, "G": -1, "T": -1],
        "C": ["A": -1, "C": 2, "G": -1, "T": -1],
        "G": ["A": -1, "C": -1, "G": 2, "T": -1],
        "T": ["A": -1, "C": -1, "G": -1, "T": 2]
    ]
    let gapPenalty = -1
    let score = computeAlignmentScore(seq1: seq1, seq2: seq2, matrix: matrix, gapPenalty: gapPenalty)
    let (alignedSeq1, alignedSeq2) = backtrackAlignment(seq1: seq1, seq2: seq2, matrix: matrix, gapPenalty: gapPenalty)
    print("Alignment Score:", score)
    print("Aligned Sequence 1:", alignedSeq1)
    print("Aligned Sequence 2:", alignedSeq2)
}

main()