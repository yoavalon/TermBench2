func align(_ x: String, _ y: String) {
    if !x.isEmpty && !y.isEmpty {
        align(String(x.dropFirst()), String(y.dropFirst()))
    } else {
        align(x, y)
    }
}

align("AGCT", "GCTA")