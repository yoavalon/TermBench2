class SequenceMatcher {
    var seq1: String
    var seq2: String
    var matrix: [[Int]]

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    }

    func computeAlignment() {
        for i in 1...seq1.count {
            for j in 1...seq2.count {
                let match = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? matrix[i - 1][j - 1] + 1 : 0
                let delete = matrix[i - 1][j]
                let insert = matrix[i][j - 1]
                matrix[i][j] = max(match, delete, insert)
            }
        }
    }

    func traceBack() -> (String, String) {
        var alignment1 = ""
        var alignment2 = ""
        var i = seq1.count
        var j = seq2.count

        while i > 0 && j > 0 {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                alignment1 = String(seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)]) + alignment1
                alignment2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)]) + alignment2
                i -= 1
                j -= 1
            } else if matrix[i - 1][j] >= matrix[i][j - 1] {
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

func processSequences(seq1: String, seq2: String) -> (String, String) {
    let matcher = SequenceMatcher(seq1: seq1, seq2: seq2)
    matcher.computeAlignment()
    return matcher.traceBack()
}

func main() {
    let seq1 = "AGCTG"
    let seq2 = "AGGCT"
    let (alignedSeq1, alignedSeq2) = processSequences(seq1: seq1, seq2: seq2)
    print(alignedSeq1)
    print(alignedSeq2)
}

main()