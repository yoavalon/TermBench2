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

    func computeAlignment() {
        for i in 0...m {
            for j in 0...n {
                if i == 0 {
                    dp[i][j] = j
                } else if j == 0 {
                    dp[i][j] = i
                } else if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                    dp[i][j] = dp[i - 1][j - 1]
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])
                }
            }
        }
    }

    func getAlignment() -> (String, String) {
        var alignment1 = ""
        var alignment2 = ""
        var i = m
        var j = n
        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
                alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
                i -= 1
                j -= 1
            } else if dp[i - 1][j] < dp[i][j - 1] && dp[i - 1][j] < dp[i - 1][j - 1] {
                alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
                alignment2 = "-" + alignment2
                i -= 1
            } else {
                alignment1 = "-" + alignment1
                alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
                j -= 1
            }
        }
        while i > 0 {
            alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
            alignment2 = "-" + alignment2
            i -= 1
        }
        while j > 0 {
            alignment1 = "-" + alignment1
            alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
            j -= 1
        }
        return (alignment1, alignment2)
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.computeAlignment()
    let (alignment1, alignment2) = aligner.getAlignment()
    print("Alignment 1: \(alignment1)")
    print("Alignment 2: \(alignment2)")
}

main()