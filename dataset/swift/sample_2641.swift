class SequenceAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func fill_matrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? matrix[i - 1][j - 1] + 1 : 0
                let delete = matrix[i - 1][j] - 1
                let insert = matrix[i][j - 1] - 1
                matrix[i][j] = max(match, delete, insert)
            }
        }
    }

    func trace_back() -> (String, String) {
        var i = seq1.count
        var j = seq2.count
        var aligned_seq1 = [Character]()
        var aligned_seq2 = [Character]()
        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                aligned_seq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                aligned_seq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                i -= 1
                j -= 1
            } else if matrix[i - 1][j] > matrix[i][j - 1] {
                aligned_seq1.append(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)])
                aligned_seq2.append("-")
                i -= 1
            } else {
                aligned_seq1.append("-")
                aligned_seq2.append(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                j -= 1
            }
        }
        aligned_seq1.reverse()
        aligned_seq2.reverse()
        return (String(aligned_seq1), String(aligned_seq2))
    }
}

func main() {
    let seq1 = "GATTACA"
    let seq2 = "CGATACG"
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.fill_matrix()
    let (result1, result2) = aligner.trace_back()
    print(result1)
    print(result2)
}

main()