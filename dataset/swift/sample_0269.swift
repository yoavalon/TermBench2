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

    func initialize_matrix() {
        for i in 0...seq1.count {
            matrix[i][0] = i
        }
        for j in 0...seq2.count {
            matrix[0][j] = j
        }
    }

    func fill_matrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let cost = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1
                matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost)
            }
        }
    }

    func trace_back() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var align1 = ""
        var align2 = ""

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                i -= 1
                j -= 1
            } else if i > 0 && matrix[i][j] == matrix[i - 1][j] + 1 {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = "-" + align2
                i -= 1
            } else {
                align1 = "-" + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                j -= 1
            }
        }
        return (align1, align2)
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initialize_matrix()
    aligner.fill_matrix()
    let aligned_sequences = aligner.trace_back()
    print("Aligned Sequence 1:", aligned_sequences.0)
    print("Aligned Sequence 2:", aligned_sequences.1)
}

main()