class SequenceAligner {
    var seq1: String
    var seq2: String

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func score(_ a: Character, _ b: Character) -> Int {
        return a == b ? 1 : -1
    }

    func align() -> (String, String) {
        let m = seq1.count
        let n = seq2.count
        var matrix = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 1...m {
            matrix[i][0] = i
        }
        for j in 1...n {
            matrix[0][j] = j
        }
        for i in 1...m {
            for j in 1...n {
                let match = matrix[i - 1][j - 1] + score(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                let delete = matrix[i - 1][j] + 1
                let insert = matrix[i][j - 1] + 1
                matrix[i][j] = min(match, delete, insert)
            }
        }
        return traceback(matrix, m, n)
    }

    func traceback(_ matrix: [[Int]], _ i: Int, _ j: Int) -> (String, String) {
        var align1 = ""
        var align2 = ""
        var i = i
        var j = j
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + score(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) {
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
    let result = aligner.align()
    print("Alignment 1:", result.0)
    print("Alignment 2:", result.1)
}

main()