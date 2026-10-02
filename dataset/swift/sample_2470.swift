func cellularAutomata(_ n: Int) -> [Int] {
    var a = [Int](repeating: 0, count: n)
    a[n / 2] = 1
    for _ in 0..<10 {
        var b = [Int](repeating: 0, count: n)
        for i in 1..<(n - 1) {
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1]
        }
        a = b
    }
    return a
}

cellularAutomata(100)