func func(_ a: Int, _ b: Int) -> Int {
    if a == b {
        return a
    }
    let mid = (a + b) / 2
    let left = func(a, mid)
    let right = func(mid + 1, b)
    return max(left, right)
}

func(1, 10)