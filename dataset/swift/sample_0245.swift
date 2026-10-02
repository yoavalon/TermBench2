class GenomicAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func _fillMatrix() {
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

    func _traceback() -> ([Character], [Character]) {
        var alignment1: [Character] = []
        var alignment2: [Character] = []
        var i = seq1.count
        var j = seq2.count
        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                alignment1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignment2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if matrix[i - 1][j] > matrix[i][j - 1] {
                alignment1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                alignment2.append("-")
                i -= 1
            } else {
                alignment1.append("-")
                alignment2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                j -= 1
            }
        }
        alignment1.reverse()
        alignment2.reverse()
        return (alignment1, alignment2)
    }

    func align() -> ([Character], [Character]) {
        _fillMatrix()
        return _traceback()
    }
}

func main() {
    let seq1 = "AGTACGCA"
    let seq2 = "TGACGTCA"
    let aligner = GenomicAligner(seq1: seq1, seq2: seq2)
    let result = aligner.align()
    print("Alignment 1:", String(result.0))
    print("Alignment 2:", String(result.1))
}

main()