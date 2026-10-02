class SequenceAligner {
    var seq1: String
    var seq2: String
    var scoreMatrix: [[Int]]
    var traceMatrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.scoreMatrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
        self.traceMatrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fillMatrices() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = scoreMatrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
                let delete = scoreMatrix[i - 1][j] - 1
                let insert = scoreMatrix[i][j - 1] - 1
                scoreMatrix[i][j] = max(match, delete, insert)
                if scoreMatrix[i][j] == match {
                    traceMatrix[i][j] = 1
                } else if scoreMatrix[i][j] == delete {
                    traceMatrix[i][j] = 2
                } else {
                    traceMatrix[i][j] = 3
                }
            }
        }
    }

    func traceBack() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var alignedSeq1 = [Character]()
        var alignedSeq2 = [Character]()
        while i > 0 && j > 0 {
            if traceMatrix[i][j] == 1 {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if traceMatrix[i][j] == 2 {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append("-")
                i -= 1
            } else {
                alignedSeq1.append("-")
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                j -= 1
            }
        }
        alignedSeq1.reverse()
        alignedSeq2.reverse()
        return (String(alignedSeq1), String(alignedSeq2))
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.fillMatrices()
    let (alignedSeq1, alignedSeq2) = aligner.traceBack()
    print("Aligned Sequence 1:", alignedSeq1)
    print("Aligned Sequence 2:", alignedSeq2)
}

main()