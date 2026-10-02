func compute_similarity(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            if Array(seq1)[i - 1] == Array(seq2)[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[len1][len2]
}

func generate_sequences() -> AnyIterator<(String, String)> {
    var seq1 = "ACGT"
    var seq2 = "ACGTC"
    return AnyIterator {
        defer {
            seq1.append("A")
            seq2.append("C")
        }
        return (seq1, seq2)
    }
}

func main() {
    let sequences = generate_sequences()
    while let (seq1, seq2) = sequences.next() {
        let similarity = compute_similarity(seq1: seq1, seq2: seq2)
        print("Similarity between \(seq1) and \(seq2): \(similarity)")
    }
}

main()