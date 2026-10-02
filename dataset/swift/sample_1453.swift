import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]
    var traceback: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
        self.traceback = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fillMatrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
                let delete = matrix[i - 1][j] - 1
                let insert = matrix[i][j - 1] - 1
                matrix[i][j] = max(match, delete, insert)
                if matrix[i][j] == match {
                    traceback[i][j] = 1
                } else if matrix[i][j] == delete {
                    traceback[i][j] = 2
                } else {
                    traceback[i][j] = 3
                }
            }
        }
    }

    func alignSequences() -> (String, String) {
        var alignedSeq1 = ""
        var alignedSeq2 = ""
        var i = seq1.count
        var j = seq2.count
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && traceback[i][j] == 1 {
                alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignedSeq1
                alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignedSeq2
                i -= 1
                j -= 1
            } else if i > 0 && (j == 0 || traceback[i][j] == 2) {
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
    let seq2 = "CGATTACG"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.fillMatrix()
    let (alignedSeq1, alignedSeq2) = aligner.alignSequences()
    print(alignedSeq1)
    print(alignedSeq2)
}

main()