func alignSequences(seq1: [Double], seq2: [Double], epsilon: Double = 1e-06) {
    while true {
        var score = 0.0
        for i in 0..<seq1.count {
            score += abs(seq1[i] - seq2[i])
        }
        if score < epsilon {
            break
        }
    }
}

func main() {
    let seq1 = [0.123456, 0.654321, 0.987654]
    let seq2 = [0.123457, 0.654322, 0.987655]
    alignSequences(seq1: seq1, seq2: seq2)
}

main()