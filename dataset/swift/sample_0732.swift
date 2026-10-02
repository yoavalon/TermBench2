func align(seq1: String, seq2: String) -> (Int, String) {
    if seq1.isEmpty || seq2.isEmpty {
        return (0, "")
    }
    if seq1.first == seq2.first {
        let (score, alignment) = align(seq1: String(seq1.dropFirst()), seq2: String(seq2.dropFirst()))
        return (score + 1, String(seq1.first!) + alignment)
    } else {
        let (score1, alignment1) = align(seq1: String(seq1.dropFirst()), seq2: seq2)
        let (score2, alignment2) = align(seq1: seq1, seq2: String(seq2.dropFirst()))
        if score1 > score2 {
            return (score1, "-" + alignment1)
        } else {
            return (score2, alignment2 + "-")
        }
    }
}

func main() {
    let seq1 = "AGCTG"
    let seq2 = "AGGCT"
    let (score, alignment) = align(seq1: seq1, seq2: seq2)
    print(score, alignment)
}

main()