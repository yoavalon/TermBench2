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

    func initialize_matrix() {
        let len1 = seq1.count
        let len2 = seq2.count
        matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
        for i in 0...len1 {
            matrix![i][0] = i
        }
        for j in 0...len2 {
            matrix![0][j] = j
        }
    }

    func compute_alignment() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let cost = seq1.index(seq1.startIndex, offsetBy: i - 1)..<seq1.index(seq1.startIndex, offsetBy: i) == seq2.index(seq2.startIndex, offsetBy: j - 1)..<seq2.index(seq2.startIndex, offsetBy: j) ? 0 : 1
                matrix![i][j] = min(matrix![i - 1][j] + 1, matrix![i][j - 1] + 1, matrix![i - 1][j - 1] + cost)
            }
        }
    }

    func backtrack_alignment() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var align1 = ""
        var align2 = ""
        while i > 0 && j > 0 {
            if seq1.index(seq1.startIndex, offsetBy: i - 1)..<seq1.index(seq1.startIndex, offsetBy: i) == seq2.index(seq2.startIndex, offsetBy: j - 1)..<seq2.index(seq2.startIndex, offsetBy: j) {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                i -= 1
                j -= 1
            } else if matrix![i - 1][j] + 1 == matrix![i][j] {
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
    let seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"
    let seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initialize_matrix()
    aligner.compute_alignment()
    let alignment = aligner.backtrack_alignment()
    print("Aligned Sequence 1:", alignment.0)
    print("Aligned Sequence 2:", alignment.1)
}

main()