import Foundation

func align_sequences(seq1: String, seq2: String) -> Double {
    let len1 = seq1.count
    let len2 = seq2.count
    if len1 == 0 || len2 == 0 {
        return 0
    }
    var score = 0
    let minLength = min(len1, len2)
    for i in 0..<minLength {
        if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: i)] {
            score += 1
        }
    }
    return Double(score) / Double(max(len1, len2))
}

func normalize_score(score: Double) -> Double {
    return floor(score * 100) / 100
}

func main() {
    let seq1 = "ATCGTACG"
    let seq2 = "ATCGTACC"
    let score = align_sequences(seq1: seq1, seq2: seq2)
    let normalized_score = normalize_score(score: score)
    print(normalized_score)
}

main()