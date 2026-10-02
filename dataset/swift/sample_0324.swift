func simulate() {
    var grid = Array(repeating: Array(repeating: 0, count: 50), count: 50)
    while true {
        var new_grid = Array(repeating: Array(repeating: 0, count: 50), count: 50)
        for i in 1..<49 {
            for j in 1..<49 {
                let neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]
                new_grid[i][j] = neighbors == 2 ? 1 : 0
            }
        }
        grid = new_grid
    }
}

simulate()