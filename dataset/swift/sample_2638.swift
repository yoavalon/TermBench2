import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fillMatrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? matrix[i - 1][j - 1] + 1 : 0
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1], match)
            }
        }
    }

    func traceback() -> (String, String) {
        var alignedSeq1 = [Character]()
        var alignedSeq2 = [Character]()
        var i = seq1.count
        var j = seq2.count
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if i > 0 && matrix[i][j] == matrix[i - 1][j] {
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
    aligner.fillMatrix()
    let (alignedSeq1, alignedSeq2) = aligner.traceback()
    print(alignedSeq1)
    print(alignedSeq2)
}

main()