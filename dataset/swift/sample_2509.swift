func computeSimilarity(seq1: String, seq2: String) -> Double {
    let length = min(seq1.count, seq2.count)
    var score = 0
    for i in 0..<length {
        if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: i)] {
            score += 1
        }
    }
    return Double(score) / Double(length)
}

func alignSequences(seq1: String, seq2: String) -> (String, String) {
    var maxScore = 0.0
    var bestAlignment: (String, String) = (seq1, seq2)
    for i in 0..<seq2.count {
        let shiftedSeq = String(seq2.suffix(seq2.count - i)) + String(seq2.prefix(i))
        let score = computeSimilarity(seq1: seq1, seq2: shiftedSeq)
        if score > maxScore {
            maxScore = score
            bestAlignment = (seq1, shiftedSeq)
        }
    }
    return bestAlignment
}

func main() {
    let sequence1 = "ACGTACGTAC"
    let sequence2 = "TACGTACGTA"
    let alignedSequences = alignSequences(seq1: sequence1, seq2: sequence2)
    print("Aligned Sequences:", alignedSequences)
}

main()