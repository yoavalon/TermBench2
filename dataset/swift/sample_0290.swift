class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]
    var scoreMatrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
        self.scoreMatrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func initializeMatrices() {
        for i in 0...seq1.count {
            matrix[i][0] = i
            scoreMatrix[i][0] = i * -2
        }
        for j in 0...seq2.count {
            matrix[0][j] = j
            scoreMatrix[0][j] = j * -2
        }
    }

    func calculateScores() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = scoreMatrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : -1)
                let delete = scoreMatrix[i - 1][j] - 2
                let insert = scoreMatrix[i][j - 1] - 2
                scoreMatrix[i][j] = max(match, delete, insert)
            }
        }
    }

    func traceBack() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var alignedSeq1 = ""
        var alignedSeq2 = ""
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : -1) {
                alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignedSeq1
                alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignedSeq2
                i -= 1
                j -= 1
            } else if i > 0 && scoreMatrix[i][j] == scoreMatrix[i - 1][j] - 2 {
                alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignedSeq1
                alignedSeq2 = "-" + alignedSeq2
                i -= 1
            } else {
                alignedSeq1 = "-" + alignedSeq1
                alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignedSeq2
                j -= 1
            }
        }
        return (alignedSeq1, alignedSeq2)
    }
}

func main() {
    let seq1 = "GATTACA"
    let seq2 = "GATTCACA"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initializeMatrices()
    aligner.calculateScores()
    let (alignedSeq1, alignedSeq2) = aligner.traceBack()
    print("Aligned Sequence 1:", alignedSeq1)
    print("Aligned Sequence 2:", alignedSeq2)
}

main()