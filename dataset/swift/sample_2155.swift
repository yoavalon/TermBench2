func simulate_flow(n: Int) {
    var grid = Array(repeating: Array(repeating: 0.0, count: n), count: n)
    while true {
        var new_grid = Array(repeating: Array(repeating: 0.0, count: n), count: n)
        for i in 0..<n {
            for j in 0..<n {
                new_grid[i][j] = (grid[i][(j - 1 + n) % n] + grid[i][(j + 1) % n] + grid[(i - 1 + n) % n][j] + grid[(i + 1) % n][j]) / 4
            }
        }
        grid = new_grid
    }
}

simulate_flow(n: 10)