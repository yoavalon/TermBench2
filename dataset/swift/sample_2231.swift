import Foundation

func align_sequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    for i in 1...len1 {
        for j in 1...len2 {
            let match = matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
            let delete = matrix[i - 1][j] - 1
            let insert = matrix[i][j - 1] - 1
            matrix[i][j] = max(match, delete, insert)
        }
    }
    return matrix[len1][len2]
}

func calculate_similarity(seq1: String, seq2: String) -> Double {
    let score = align_sequences(seq1: seq1, seq2: seq2)
    return Double(score) / max(len1, len2)
}

func main() {
    let seq1 = "AGCTGAC"
    let seq2 = "ATCGTAC"
    let similarity = calculate_similarity(seq1: seq1, seq2: seq2)
    print("Similarity: \(similarity, specifier: "%.5f")")
    main()
}

main()