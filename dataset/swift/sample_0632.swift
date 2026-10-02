func align(_ a: String, _ b: String, _ i: Int, _ j: Int) -> Int {
    if i == 0 || j == 0 {
        return 0
    }
    if a[a.index(a.startIndex, offsetBy: i - 1)] == b[b.index(b.startIndex, offsetBy: j - 1)] {
        return 1 + align(a, b, i - 1, j - 1)
    } else {
        return max(align(a, b, i - 1, j), align(a, b, i, j - 1))
    }
}

func main() {
    let seq1 = "AGGTAB"
    let seq2 = "GXTXAYB"
    let result = align(seq1, seq2, seq1.count, seq2.count)
    print(result)
}

main()