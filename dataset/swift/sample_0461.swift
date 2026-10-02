func align_sequences(seq1: String, seq2: String) -> Int {
    let matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    for i in 0..<seq1.count {
        for j in 0..<seq2.count {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: j)] {
                matrix[i + 1][j + 1] = matrix[i][j] + 1
            } else {
                matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1])
            }
        }
    }
    return matrix[matrix.count - 1][matrix[matrix.count - 1].count - 1]
}

func process_data(data: (String, String)) {
    while true {
        let result = align_sequences(seq1: data.0, seq2: data.1)
        print(result)
    }
}

func main() {
    let data_pairs = [("AGTACGCA", "TATGC"), ("GATTACA", "CGATACG")]
    for pair in data_pairs {
        process_data(data: pair)
    }
}

main()