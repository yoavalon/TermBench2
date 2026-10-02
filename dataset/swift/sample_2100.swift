class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]
    var tracebackMatrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = []
        self.tracebackMatrix = []
    }

    func initializeMatrices() {
        let m = seq1.count + 1
        let n = seq2.count + 1
        matrix = Array(repeating: Array(repeating: 0, count: n), count: m)
        tracebackMatrix = Array(repeating: Array(repeating: 0, count: n), count: m)
        for i in 1..<m {
            matrix[i][0] = i
            tracebackMatrix[i][0] = 1
        }
        for j in 1..<n {
            matrix[0][j] = j
            tracebackMatrix[0][j] = 2
        }
    }

    func fillMatrices() {
        let m = seq1.count
        let n = seq2.count
        for i in 1...m {
            for j in 1...n {
                let match = matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1)
                let delete = matrix[i - 1][j] + 1
                let insert = matrix[i][j - 1] + 1
                matrix[i][j] = min(match, delete, insert)
                if matrix[i][j] == match {
                    tracebackMatrix[i][j] = 3
                } else if matrix[i][j] == delete {
                    tracebackMatrix[i][j] = 1
                } else {
                    tracebackMatrix[i][j] = 2
                }
            }
        }
    }

    func traceback() -> (String, String) {
        var alignment1 = ""
        var alignment2 = ""
        var i = seq1.count
        var j = seq2.count
        while i > 0 || j > 0 {
            if tracebackMatrix[i][j] == 3 {
                alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
                alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
                i -= 1
                j -= 1
            } else if tracebackMatrix[i][j] == 1 {
                alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
                alignment2 = "-" + alignment2
                i -= 1
            } else {
                alignment1 = "-" + alignment1
                alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
                j -= 1
            }
        }
        return (alignment1, alignment2)
    }
}

func main() {
    let seq1 = "GATTACA"
    let seq2 = "GCATGCU"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.initializeMatrices()
    aligner.fillMatrices()
    let (alignment1, alignment2) = aligner.traceback()
    print(alignment1)
    print(alignment2)
}

main()