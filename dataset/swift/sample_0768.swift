func align(_ seq1: String, _ seq2: String) -> Int {
    if seq1.isEmpty || seq2.isEmpty {
        return 0
    }
    if seq1.first == seq2.first {
        return 1 + align(String(seq1.dropFirst()), String(seq2.dropFirst()))
    } else {
        let align1 = align(String(seq1.dropFirst()), seq2)
        let align2 = align(seq1, String(seq2.dropFirst()))
        return max(align1, align2)
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let result = align(seq1, seq2)
    print(result)
}

main()