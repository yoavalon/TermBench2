import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]?

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = nil
    }

    func createMatrix() {
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fillMatrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = matrix![i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
                let delete = matrix![i - 1][j] - 1
                let insert = matrix![i][j - 1] - 1
                matrix![i][j] = max(match, delete, insert)
            }
        }
    }

    func traceBack() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var align1: [Character] = []
        var align2: [Character] = []

        while i > 0 && j > 0 {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]
            if char1 == char2 {
                align1.append(char1)
                align2.append(char2)
                i -= 1
                j -= 1
            } else if matrix![i - 1][j] > matrix![i][j - 1] {
                align1.append(char1)
                align2.append("-")
                i -= 1
            } else {
                align1.append("-")
                align2.append(char2)
                j -= 1
            }
        }
        while i > 0 {
            align1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
            align2.append("-")
            i -= 1
        }
        while j > 0 {
            align1.append("-")
            align2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
            j -= 1
        }
        return (String(align1.reversed()), String(align2.reversed()))
    }
}

func main() {
    let seq1 = "GATTACA"
    let seq2 = "GCATGCU"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.createMatrix()
    aligner.fillMatrix()
    let (alignedSeq1, alignedSeq2) = aligner.traceBack()
    print(alignedSeq1)
    print(alignedSeq2)
}

main()