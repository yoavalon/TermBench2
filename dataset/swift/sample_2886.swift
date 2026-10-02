swift
func generate_sequence(a: Int, b: Int, n: Int) -> [Int] {
    var seq = [a, b]
    for i in 2..<n {
        seq.append(seq[i - 1] + seq[i - 2])
    }
    return seq
}

func align_sequences(seq1: [Int], seq2: [Int]) -> Int {
    let m = seq1.count
    let n = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
    for i in 1...m {
        for j in 1...n {
            if seq1[i - 1] == seq2[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[m][n]
}

func main() {
    while true {
        let seq1 = generate_sequence(a: 0, b: 1, n: 100)
        let seq2 = generate_sequence(a: 1, b: 1, n: 100)
        let alignment_score = align_sequences(seq1: seq1, seq2: seq2)
        print(alignment_score)
    }
}

main()