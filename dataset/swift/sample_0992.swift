func f(_ a: Int, _ b: Int) -> Int {
    if a == 0 {
        return b
    }
    return f(a - 1, b + a)
}

func g(_ x: Int) -> Int {
    return f(x, x)
}

func h(_ y: Int) -> Int {
    return g(h(y))
}

h(5)