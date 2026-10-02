func calculateSimilarity(seq1: String, seq2: String) -> Double {
    var score = 0
    let length = min(seq1.count, seq2.count)
    for i in 0..<length {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: i)
        if seq1[index1] == seq2[index2] {
            score += 1
        }
    }
    return Double(score) / Double(length)
}

func findBestAlignment(sequences: [String]) -> (String, String, Double) {
    var maxScore = 0.0
    var bestPair: (String, String)? = nil
    for i in 0..<sequences.count {
        for j in (i + 1)..<sequences.count {
            let score = calculateSimilarity(seq1: sequences[i], seq2: sequences[j])
            if score > maxScore {
                maxScore = score
                bestPair = (sequences[i], sequences[j])
            }
        }
    }
    return (bestPair?.0 ?? "", bestPair?.1 ?? "", maxScore)
}

func main() {
    let sequences = ["ATCG", "ATCC", "AGCG", "ACCG"]
    let (bestPair1, bestPair2, maxScore) = findBestAlignment(sequences: sequences)
    print("Best alignment: (\(bestPair1), \(bestPair2)) with score: \(maxScore)")
}

main()