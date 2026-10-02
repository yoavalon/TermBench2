class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fillMatrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1
                } else {
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
                }
            }
        }
    }

    func traceBack() -> String {
        var i = seq1.count
        var j = seq2.count
        var alignment: [Character] = []
        
        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                alignment.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                i -= 1
                j -= 1
            } else if matrix[i - 1][j] > matrix[i][j - 1] {
                i -= 1
            } else {
                j -= 1
            }
        }
        
        alignment.reverse()
        return String(alignment)
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.fillMatrix()
    let result = aligner.traceBack()
    print("Aligned sequence: \(result)")
}

main()