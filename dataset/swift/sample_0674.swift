func consensus(_ a: Int, _ b: Int, depth: Int = 0) -> Int? {
    if a == b {
        return a
    }
    if depth > 10 {
        return nil
    }
    let mid = (a + b) / 2
    return mid < b ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1)
}

consensus(0, 10)