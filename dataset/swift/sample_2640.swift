import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var m: Int
    var n: Int
    var dp: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.m = seq1.count
        self.n = seq2.count
        self.dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    }

    func calculate_score() {
        for i in 1...m {
            for j in 1...n {
                let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
                let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
                if seq1[char1] == seq2[char2] {
                    self.dp[i][j] = self.dp[i - 1][j - 1] + 1
                } else {
                    self.dp[i][j] = max(self.dp[i - 1][j], self.dp[i][j - 1])
                }
            }
        }
    }

    func traceback() -> (String, String) {
        var i = m
        var j = n
        var align1 = ""
        var align2 = ""
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && (seq1.index(seq1.startIndex, offsetBy: i - 1) == seq2.index(seq2.startIndex, offsetBy: j - 1)) {
                let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
                let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
                align1 = String(seq1[char1]) + align1
                align2 = String(seq2[char2]) + align2
                i -= 1
                j -= 1
            } else if i > 0 && self.dp[i][j] == self.dp[i - 1][j] {
                let char1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
                align1 = String(seq1[char1]) + align1
                align2 = "-" + align2
                i -= 1
            } else {
                let char2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
                align1 = "-" + align1
                align2 = String(seq2[char2]) + align2
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
    aligner.calculate_score()
    let result = aligner.traceback()
    print("Aligned Sequence 1:", result.0)
    print("Aligned Sequence 2:", result.1)
}

main()