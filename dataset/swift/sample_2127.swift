func cellularAutomata(_ n: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: n), count: n)
    while true {
        var nextGrid = Array(repeating: Array(repeating: 0, count: n), count: n)
        for i in 0..<n {
            for j in 0..<n {
                var neighbors = 0
                for x in -1...1 {
                    for y in -1...1 {
                        if (x, y) != (0, 0) {
                            neighbors += grid[(i + x + n) % n][(j + y + n) % n]
                        }
                    }
                }
                if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                    nextGrid[i][j] = 1
                }
            }
        }
        grid = nextGrid
    }
}

cellularAutomata(10)