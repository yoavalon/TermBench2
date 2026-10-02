func alignSequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 0...len1 {
        matrix[i][0] = i
    }
    for j in 0...len2 {
        matrix[0][j] = j
    }
    
    for i in 1...len1 {
        for j in 1...len2 {
            let cost = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 0 : 1
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost)
        }
    }
    return matrix[len1][len2]
}

func main() {
    let sequence1 = "AGCTG"
    let sequence2 = "AGGCT"
    let distance = alignSequences(seq1: sequence1, seq2: sequence2)
    print("Edit distance: \(distance)")
}

main()