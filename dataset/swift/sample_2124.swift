func cellularAutomata(_ n: Int) {
    var a = Array(repeating: Array(repeating: 0, count: n), count: n)
    while true {
        var b = Array(repeating: Array(repeating: 0, count: n), count: n)
        for i in 0..<n {
            for j in 0..<n {
                b[i][j] = (a[i][j] + a[(i - 1 + n) % n][j] + a[i][(j - 1 + n) % n] + a[(i + 1) % n][j] + a[i][(j + 1) % n]) / 5
            }
        }
        a = b
    }
}

cellularAutomata(10)