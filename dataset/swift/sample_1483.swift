import Foundation

class SequenceAligner {
    var seq1: String
    var seq2: String
    var scoreMatrix: [[Int]]
    var tracebackMatrix: [[Int]]
    var maxScore: Int
    var maxPosition: (Int, Int)

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.scoreMatrix = []
        self.tracebackMatrix = []
        self.maxScore = 0
        self.maxPosition = (0, 0)
    }

    func initializeMatrices() {
        let len1 = seq1.count
        let len2 = seq2.count
        for _ in 0...len1 {
            scoreMatrix.append(Array(repeating: 0, count: len2 + 1))
            tracebackMatrix.append(Array(repeating: 0, count: len2 + 1))
        }
    }

    func fillMatrices() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = scoreMatrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : -1)
                let delete = scoreMatrix[i - 1][j] - 1
                let insert = scoreMatrix[i][j - 1] - 1
                scoreMatrix[i][j] = max(match, delete, insert)
                if scoreMatrix[i][j] == match {
                    tracebackMatrix[i][j] = 1
                } else if scoreMatrix[i][j] == delete {
                    tracebackMatrix[i][j] = 2
                } else {
                    tracebackMatrix[i][j] = 3
                }
                if scoreMatrix[i][j] > maxScore {
                    maxScore = scoreMatrix[i][j]
                    maxPosition = (i, j)
                }
            }
        }
    }

    func backtrack() -> (String, String) {
        var alignedSeq1 = [Character]()
        var alignedSeq2 = [Character]()
        var i = maxPosition.0
        var j = maxPosition.1
        while i > 0 && j > 0 {
            if tracebackMatrix[i][j] == 1 {
                alignedSeq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignedSeq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if tracebackMatrix[i][j] == 2 {
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
    let seq1 = "AGCTG"
    let seq2 = "CGTAT"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initializeMatrices()
    aligner.fillMatrices()
    let (alignedSeq1, alignedSeq2) = aligner.backtrack()
    print(alignedSeq1)
    print(alignedSeq2)
}

main()