class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func initializeMatrix() {
        for i in 0...seq1.count {
            matrix[i][0] = i
        }
        for j in 0...seq2.count {
            matrix[0][j] = j
        }
    }

    func computeSimilarity() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1)
                let delete = matrix[i - 1][j] + 1
                let insert = matrix[i][j - 1] + 1
                matrix[i][j] = min(match, delete, insert)
            }
        }
    }

    func traceBack() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var alignedSeq1 = ""
        var alignedSeq2 = ""

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1) {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if i > 0 && matrix[i][j] == matrix[i - 1][j] + 1 {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append("-")
                i -= 1
            } else {
                alignedSeq1.append("-")
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                j -= 1
            }
        }

        return (String(alignedSeq1.reversed()), String(alignedSeq2.reversed()))
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initializeMatrix()
    aligner.computeSimilarity()
    let (alignedSeq1, alignedSeq2) = aligner.traceBack()
    print("Aligned Sequence 1:", alignedSeq1)
    print("Aligned Sequence 2:", alignedSeq2)
}

main()