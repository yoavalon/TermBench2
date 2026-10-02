class SequenceAligner {
    var seq1: String
    var seq2: String
    let match = 1
    let mismatch = -1
    let gap = -2

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func score(_ a: Character, _ b: Character) -> Int {
        return a == b ? match : mismatch
    }

    func calculateScores() -> [[Int]] {
        let m = seq1.count
        let n = seq2.count
        var matrix = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 1...m {
            for j in 1...n {
                let diagonal = matrix[i - 1][j - 1] + score(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                let up = matrix[i - 1][j] + gap
                let left = matrix[i][j - 1] + gap
                matrix[i][j] = max(diagonal, up, left)
            }
        }
        return matrix
    }

    func traceBack(_ matrix: [[Int]]) -> (String, String) {
        var m = seq1.count
        var n = seq2.count
        var alignedSeq1 = ""
        var alignedSeq2 = ""
        while m > 0 || n > 0 {
            if m > 0 && n > 0 && matrix[m][n] == matrix[m - 1][n - 1] + score(seq1[seq1.index(seq1.startIndex, offsetBy: m - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: n - 1)]) {
                alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: m - 1)]) + alignedSeq1
                alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: n - 1)]) + alignedSeq2
                m -= 1
                n -= 1
            } else if m > 0 && matrix[m][n] == matrix[m - 1][n] + gap {
                alignedSeq1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: m - 1)]) + alignedSeq1
                alignedSeq2 = "-" + alignedSeq2
                m -= 1
            } else if n > 0 {
                alignedSeq1 = "-" + alignedSeq1
                alignedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: n - 1)]) + alignedSeq2
                n -= 1
            }
        }
        return (alignedSeq1, alignedSeq2)
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    let scores = aligner.calculateScores()
    let (alignedSeq1, alignedSeq2) = aligner.traceBack(scores)
    print("Aligned Seq 1: \(alignedSeq1)")
    print("Aligned Seq 2: \(alignedSeq2)")
}

main()