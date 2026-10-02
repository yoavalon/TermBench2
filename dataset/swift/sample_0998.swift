func recursiveAlign(seq1: String, seq2: String, i: Int, j: Int) {
    if i < seq1.count && j < seq2.count {
        recursiveAlign(seq1: seq1, seq2: seq2, i: i + 1, j: j + 1)
    } else {
        recursiveAlign(seq1: seq1, seq2: seq2, i: i, j: j)
    }
}

func main() {
    let seq1 = "ACGT"
    let seq2 = "ACGGT"
    recursiveAlign(seq1: seq1, seq2: seq2, i: 0, j: 0)
}

main()