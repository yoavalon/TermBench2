func process_sequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var align_matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let match = seq1.index(seq1.startIndex, offsetBy: i - 1) == seq2.index(seq2.startIndex, offsetBy: j - 1) ? align_matrix[i - 1][j - 1] + 1 : 0
            align_matrix[i][j] = max(align_matrix[i][j - 1], align_matrix[i - 1][j], match)
        }
    }
    return align_matrix[len1][len2]
}

func main() {
    let seq1 = "ACGT"
    let seq2 = "ACCGT"
    let result = process_sequences(seq1: seq1, seq2: seq2)
    print(result)
}

main()