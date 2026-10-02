func align(_ seq1: String, _ seq2: String) -> (Int, String, String) {
    if seq1.isEmpty || seq2.isEmpty {
        return (0, seq1, seq2)
    }
    if seq1.first == seq2.first {
        let (match, alignedSeq1, alignedSeq2) = align(String(seq1.dropFirst()), String(seq2.dropFirst()))
        return (match + 1, String(seq1.first!) + alignedSeq1, String(seq2.first!) + alignedSeq2)
    } else {
        let (match1, alignedSeq1_1, alignedSeq2_1) = align(String(seq1.dropFirst()), seq2)
        let (match2, alignedSeq1_2, alignedSeq2_2) = align(seq1, String(seq2.dropFirst()))
        if match1 > match2 {
            return (match1, String(seq1.first!) + alignedSeq1_1, "-" + alignedSeq2_1)
        } else {
            return (match2, "-" + alignedSeq1_2, String(seq2.first!) + alignedSeq2_2)
        }
    }
}

func main() {
    let sequence1 = "ACGT"
    let sequence2 = "ACGA"
    let (match, alignedSeq1, alignedSeq2) = align(sequence1, sequence2)
    print("Matched: \(match), Aligned Seq1: \(alignedSeq1), Aligned Seq2: \(alignedSeq2)")
}

main()