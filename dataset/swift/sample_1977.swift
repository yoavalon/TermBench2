import Foundation

func calculateSimilarity(seq1: String, seq2: String) -> Double {
    let length = min(seq1.count, seq2.count)
    let zippped = zip(seq1.prefix(length), seq2.prefix(length))
    let identical = zippped.filter { $0 == $1 }.count
    return Double(identical) / Double(length)
}

func normalizeScore(score: Double) -> Double {
    return round(score * 100) / 100
}

func main() {
    let sequenceA = "ACGTACGTACGT"
    let sequenceB = "ACGTACGTACGA"
    let similarityScore = calculateSimilarity(seq1: sequenceA, seq2: sequenceB)
    let normalizedScore = normalizeScore(score: similarityScore)
    print(normalizedScore)
}

main()