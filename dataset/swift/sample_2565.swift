func calculateAlignmentScore(seq1: String, seq2: String) -> Int {
    var score = 0
    let minLength = min(seq1.count, seq2.count)
    for i in 0..<minLength {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: i)
        if seq1[index1] == seq2[index2] {
            score += 1
        }
    }
    return score
}

func findBestAlignment(seq1: String, seq2: String) -> (Int, Int) {
    var bestScore = 0
    var bestOffset = 0
    for offset in -seq2.count...seq1.count {
        let startIndex = max(0, -offset)
        let endIndex = seq2.count - max(0, offset)
        let shiftedSeq2 = String(seq2[seq2.index(seq2.startIndex, offsetBy: startIndex)...seq2.index(seq2.startIndex, offsetBy: endIndex)])
        let score = calculateAlignmentScore(seq1: seq1, seq2: shiftedSeq2)
        if score > bestScore {
            bestScore = score
            bestOffset = offset
        }
    }
    return (bestScore, bestOffset)
}

func main() {
    let sequence1 = "ACGTACGTACG"
    let sequence2 = "GTACGTACGTA"
    let (score, offset) = findBestAlignment(seq1: sequence1, seq2: sequence2)
    print("Best alignment score: \(score), Offset: \(offset)")
}

main()