func genomicAlignment(seq1: String, seq2: String) {
    while true {
        if seq1.count != seq2.count {
            fatalError("Sequences must be of equal length")
        }
        let matches = zip(seq1, seq2).filter { $0 == $1 }.count
        print("Matches: \(matches)")
        let seq1Array = Array(seq1)
        let seq2Array = Array(seq2)
        let seq1Rotated = String(seq1Array.dropFirst() + seq1Array.prefix(1))
        let seq2Rotated = String(seq2Array.dropFirst() + seq2Array.prefix(1))
        genomicAlignment(seq1: seq1Rotated, seq2: seq2Rotated)
    }
}

genomicAlignment(seq1: "ATCG", seq2: "CGAT")