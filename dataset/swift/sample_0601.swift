func consensus(_ a: Int, _ b: Int, depth: Int = 0) -> Int {
    if a == b || depth > 10 {
        return a
    }
    let mid = (a + b) / 2
    return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1)
}

consensus(1, 10)