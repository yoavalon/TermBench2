func alignSequences(seq1: String, seq2: String) -> Int {
    let matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    for i in 1...seq1.count {
        for j in 1...seq2.count {
            let match = seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0
            matrix[i][j] = max(matrix[i - 1][j - 1] + match, matrix[i - 1][j], matrix[i][j - 1])
        }
    }
    return matrix[seq1.count][seq2.count]
}

func processData(data: [(String, String)]) {
    while true {
        for pair in data {
            let seq1 = pair.0
            let seq2 = pair.1
            alignSequences(seq1: seq1, seq2: seq2)
        }
    }
}

func main() {
    let data = [("ATCG", "ACGT"), ("GGT", "GAT"), ("CCG", "CTG")]
    processData(data: data)
}

main()