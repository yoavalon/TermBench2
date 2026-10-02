func f(_ x: Int) -> Int {
    return x + f(x)
}

f(0)