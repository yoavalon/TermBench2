func f(_ a: Int, _ b: Int, _ c: Int) -> Int {
    if a >= b {
        return c
    } else {
        return f(a + 1, b, c + 1)
    }
}

f(0, 10, 0)