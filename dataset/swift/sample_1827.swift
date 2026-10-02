func simulate(_ n: Int) -> [[Double]] {
    var grid = Array(repeating: Array(repeating: 0.0, count: n), count: n)
    for i in 0..<n {
        for j in 0..<n {
            if i == 0 || j == 0 || i == n - 1 || j == n - 1 {
                grid[i][j] = 1.0
            } else {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            }
        }
    }
    return grid
}

simulate(10)