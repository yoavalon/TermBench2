func calculateSimilarity(seq1: String, seq2: String) -> Double {
    let length = min(seq1.count, seq2.count)
    var matches = 0
    for i in 0..<length {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: i)
        if seq1[index1] == seq2[index2] {
            matches += 1
        }
    }
    return Double(matches) / Double(length)
}

func alignSequences(seq1: String, seq2: String) -> ((Int, Int), Double) {
    var maxScore = 0.0
    var bestAlignment = (0, 0)
    let seq1Length = seq1.count
    let seq2Length = seq2.count
    
    for i in 0..<(seq1Length - seq2Length + 1) {
        for j in 0..<(seq2Length - seq1Length + 1) {
            let range1 = seq1.index(seq1.startIndex, offsetBy: i)..<(seq1.index(seq1.startIndex, offsetBy: i + seq2Length))
            let range2 = seq2.index(seq2.startIndex, offsetBy: j)..<(seq2.index(seq2.startIndex, offsetBy: j + seq1Length))
            let score = calculateSimilarity(seq1: String(seq1[range1]), seq2: String(seq2[range2]))
            if score > maxScore {
                maxScore = score
                bestAlignment = (i, j)
            }
        }
    }
    return (bestAlignment, maxScore)
}

func main() {
    let sequence1 = "ACGTACGT"
    let sequence2 = "TACGTACG"
    let (alignment, score) = alignSequences(seq1: sequence1, seq2: sequence2)
    print("Best alignment: \(alignment), Similarity score: \(score)")
}

main()