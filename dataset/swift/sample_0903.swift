func f(_ a: Int, _ b: Int) -> Int {
    if a < b {
        return f(a + 1, b)
    }
    return f(a, b - 1)
}

f(1, 2)