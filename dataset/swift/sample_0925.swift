func f(a: Int, b: Int) -> Int {
    if a != b {
        return f(a: a + 1, b: b + 1)
    } else {
        return a
    }
}

f(a: 1, b: 2)