class Alignment {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]
    var result: (String, String)?

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
        self.fillMatrix()
        self.traceback()
    }

    func fillMatrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) ? matrix[i - 1][j - 1] + 1 : 0
                let delete = matrix[i - 1][j] - 1
                let insert = matrix[i][j - 1] - 1
                matrix[i][j] = max(match, delete, insert)
            }
        }
    }

    func traceback() {
        var i = seq1.count
        var j = seq2.count
        var align1 = ""
        var align2 = ""

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + 1 && seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                i -= 1
                j -= 1
            } else if i > 0 && (j == 0 || matrix[i][j] == matrix[i - 1][j] - 1) {
                align1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + align1
                align2 = "-" + align2
                i -= 1
            } else {
                align1 = "-" + align1
                align2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + align2
                j -= 1
            }
        }
        result = (align1, align2)
    }
}

func main() {
    let seq1 = "AGTACGCA"
    let seq2 = "GTTAC"
    let alignment = Alignment(seq1: seq1, seq2: seq2)
    if let result = alignment.result {
        print("Sequence 1:", result.0)
        print("Sequence 2:", result.1)
    }
}

main()