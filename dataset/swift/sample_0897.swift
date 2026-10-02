class Alignment {
    var seq1: String
    var seq2: String
    var len1: Int
    var len2: Int

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
        self.len1 = seq1.count
        self.len2 = seq2.count
    }

    func score(i: Int, j: Int) -> Int {
        let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i)]
        let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: j)]
        return char1 == char2 ? 1 : -1
    }

    func align(i: Int, j: Int) -> (Int, String, String) {
        if i == -1 || j == -1 {
            return (0, "", "")
        }
        let (match, align1, align2) = align(i: i - 1, j: j - 1)
        let matchScore = match + score(i: i, j: j)
        let (insert, align1_ins, align2_ins) = align(i: i, j: j - 1)
        let insertScore = insert - 1
        let (delete, align1_del, align2_del) = align(i: i - 1, j: j)
        let deleteScore = delete - 1

        if matchScore >= insertScore && matchScore >= deleteScore {
            return (matchScore, String(seq1[seq1.index(seq1.startIndex, offsetBy: i)]) + align1, String(seq2[seq2.index(seq2.startIndex, offsetBy: j)]) + align2)
        } else if insertScore >= matchScore && insertScore >= deleteScore {
            return (insertScore, "_" + align1_ins, String(seq2[seq2.index(seq2.startIndex, offsetBy: j)]) + align2_ins)
        } else {
            return (deleteScore, String(seq1[seq1.index(seq1.startIndex, offsetBy: i)]) + align1_del, "_" + align2_del)
        }
    }
}

func main() {
    let sequence1 = "AGGTAB"
    let sequence2 = "GXTXAYB"
    let alignment = Alignment(seq1: sequence1, seq2: sequence2)
    let (_, alignedSeq1, alignedSeq2) = alignment.align(i: alignment.len1 - 1, j: alignment.len2 - 1)
    print("Aligned Sequence 1:", alignedSeq1)
    print("Aligned Sequence 2:", alignedSeq2)
}

main()