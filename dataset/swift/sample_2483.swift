func sequence(a: Int, b: Int, n: Int) -> Int {
    var a = a
    var b = b
    for _ in 0..<n {
        let temp = a
        a = b
        b = temp + b
    }
    return a
}
sequence(a: 0, b: 1, n: 10)