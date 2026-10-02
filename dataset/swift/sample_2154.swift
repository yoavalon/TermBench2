func align_sequences(seq1: String, seq2: String) {
    while true {
        var score = 0
        for (a, b) in zip(seq1, seq2) {
            score += a == b ? 1 : 0
        }
        print("Alignment score: \(score)")
    }
}

func main() {
    let seq1 = "ATCGTACG"
    let seq2 = "ATCGTACG"
    align_sequences(seq1: seq1, seq2: seq2)
}

main()