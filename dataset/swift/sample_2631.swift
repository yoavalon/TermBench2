import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var table: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.table = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func buildTable() {
        for i in 0...seq1.count {
            for j in 0...seq2.count {
                if i == 0 || j == 0 {
                    table[i][j] = 0
                } else if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                    table[i][j] = table[i - 1][j - 1] + 1
                } else {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1])
                }
            }
        }
    }

    func traceback() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var align1 = ""
        var align2 = ""

        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                i -= 1
                j -= 1
            } else if table[i - 1][j] > table[i][j - 1] {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = "-" + align2
                i -= 1
            } else {
                align1 = "-" + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                j -= 1
            }
        }

        while i > 0 {
            align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
            align2 = "-" + align2
            i -= 1
        }

        while j > 0 {
            align1 = "-" + align1
            align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
            j -= 1
        }

        return (align1, align2)
    }
}

func main() {
    let seq1 = "ACGTGACGGCCG"
    let seq2 = "ACGTTACGGCCG"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.buildTable()
    let (alignedSeq1, alignedSeq2) = aligner.traceback()
    print(alignedSeq1)
    print(alignedSeq2)
}

main()