import Foundation

class GenomicAligner {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func _score(_ a: Character, _ b: Character) -> Int {
        return a == b ? 1 : -1
    }

    func _fill_matrix() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = matrix[i - 1][j - 1] + _score(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)])
                let delete = matrix[i - 1][j] - 1
                let insert = matrix[i][j - 1] - 1
                matrix[i][j] = max(match, delete, insert)
            }
        }
    }

    func _traceback(_ i: Int, _ j: Int) -> (String, String) {
        if i == 0 || j == 0 {
            return ("", "")
        }
        if matrix[i][j] == matrix[i - 1][j - 1] + _score(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)], seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) {
            let (s1, s2) = _traceback(i - 1, j - 1)
            return (String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + s1, String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + s2)
        } else if matrix[i][j] == matrix[i - 1][j] - 1 {
            let (s1, s2) = _traceback(i - 1, j)
            return (String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + s1, "-" + s2)
        } else {
            let (s1, s2) = _traceback(i, j - 1)
            return ("-" + s1, String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + s2)
        }
    }

    func align() -> (String, String) {
        _fill_matrix()
        return _traceback(seq1.count, seq2.count)
    }
}

func main() {
    let seq1 = "ACGTGACGTG"
    let seq2 = "GTCGTGTCG"
    let aligner = GenomicAligner(seq1: seq1, seq2: seq2)
    let (aligned_seq1, aligned_seq2) = aligner.align()
    print("Aligned Sequence 1:", aligned_seq1)
    print("Aligned Sequence 2:", aligned_seq2)
}

main()