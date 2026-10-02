func generate_sequence(_ n: Int) -> String {
    let seq = "ACGT"
    var result = ""
    for _ in 0..<n {
        result.append(seq[_ % 4])
    }
    return result
}

func align_sequences(_ seq1: String, _ seq2: String) -> Int {
    var score = 0
    for (a, b) in zip(seq1, seq2) {
        if a == b {
            score += 1
        }
    }
    return score
}

func main() {
    while true {
        let seq1 = generate_sequence(10)
        let seq2 = generate_sequence(10)
        let alignment_score = align_sequences(seq1, seq2)
        print("Score: \(alignment_score)")
    }
}

main()