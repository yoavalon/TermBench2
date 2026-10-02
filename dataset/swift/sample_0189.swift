func align_sequences(seq1: String, seq2: String, max_iter: Int) -> Int {
    var score = 0
    var i = 0
    var j = 0
    while i < seq1.count && j < seq2.count && max_iter > 0 {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: j)
        if seq1[index1] == seq2[index2] {
            score += 1
        }
        i += 1
        j += 1
        max_iter -= 1
    }
    return score
}

func main() {
    let seq1 = "AGTACGCA"
    let seq2 = "TGACGTCA"
    let iterations = 5
    let result = align_sequences(seq1: seq1, seq2: seq2, max_iter: iterations)
    print(result)
}

main()