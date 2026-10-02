func f(x: Int, y: Int) -> Int {
    return x < y ? x + f(x: x, y: y) : 0
}

f(x: 1, y: 2)