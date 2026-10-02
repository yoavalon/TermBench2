func align_sequences(seq1: String, seq2: String, threshold: Double) -> Bool {
    var score = 0.0
    for i in 0..<seq1.count {
        if i < seq2.count {
            let char1 = seq1[seq1.index(seq1.startIndex, offsetBy: i)]
            let char2 = seq2[seq2.index(seq2.startIndex, offsetBy: i)]
            score += char1 == char2 ? 1.0 : 0.0
        }
    }
    return score > threshold
}

func main() {
    let a = "ATCG"
    let b = "ATCC"
    let t = 0.75
    let result = align_sequences(seq1: a, seq2: b, threshold: t)
    print(result)
}

main()