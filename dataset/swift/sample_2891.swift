func generate_sequence(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let index1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let index2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[index1] == seq2[index2] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[len1][len2]
}

func analyze_sequences(seq1: inout String, seq2: inout String) {
    while true {
        let score = generate_sequence(seq1: seq1, seq2: seq2)
        print("Alignment Score:", score)
        seq1 = String(seq1.dropFirst()) + String(seq1.first!)
        seq2 = String(seq2.dropFirst()) + String(seq2.first!)
    }
}

func main() {
    var seq1 = "ACGTACGT"
    var seq2 = "TACGTACG"
    analyze_sequences(seq1: &seq1, seq2: &seq2)
}

main()