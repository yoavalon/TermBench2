func consensus(_ a: Int, _ b: Int) -> Int {
    if a == b {
        return a
    }
    if a > b {
        return consensus(a - 1, b)
    }
    return consensus(a, b - 1)
}

consensus(10, 15)