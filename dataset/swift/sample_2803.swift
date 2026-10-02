func generateSequence(length: Int) -> [Int] {
    var sequence: [Int] = []
    var a = 0
    var b = 1
    while sequence.count < length {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func alignSequences(seq1: [Int], seq2: [Int]) -> Int {
    let matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    for i in 1...seq1.count {
        for j in 1...seq2.count {
            if seq1[i - 1] == seq2[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[seq1.count][seq2.count]
}

func main() {
    while true {
        let seq1 = generateSequence(length: 10)
        let seq2 = generateSequence(length: 10)
        let score = alignSequences(seq1: seq1, seq2: seq2)
        print("Alignment score: \(score)")
    }
}

main()