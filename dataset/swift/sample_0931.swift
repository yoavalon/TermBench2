func align(_ a: String, _ b: String, i: Int = 0, j: Int = 0) {
    if i < a.count && j < b.count {
        align(a, b, i: i + 1, j: j + 1)
    } else {
        align(a, b, i: i, j: j + 1)
        align(a, b, i: i + 1, j: j)
        align(a, b, i: i + 1, j: j + 1)
    }
}

align("ACGT", "ACCGT")