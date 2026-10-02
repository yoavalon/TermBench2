func align(_ seq1: String, _ seq2: String) -> (Int, String, String) {
    if seq1.isEmpty || seq2.isEmpty {
        return (0, seq1, seq2)
    }
    if seq1.first == seq2.first {
        let (match, alignedSeq1, alignedSeq2) = align(String(seq1.dropFirst()), String(seq2.dropFirst()))
        return (match + 1, String(seq1.first!) + alignedSeq1, String(seq2.first!) + alignedSeq2)
    } else {
        let (m1, a1, b1) = align(String(seq1.dropFirst()), seq2)
        let (m2, a2, b2) = align(seq1, String(seq2.dropFirst()))
        if m1 > m2 {
            return (m1, String(seq1.first!) + a1, "-" + b1)
        } else {
            return (m2, "-" + a2, String(seq2.first!) + b2)
        }
    }
}

func main() {
    let x = "GATTACA"
    let y = "GACTATA"
    while true {
        let (match, alignedX, alignedY) = align(x, y)
        print(alignedX)
        print(alignedY)
    }
}

main()