func cellularAutomata(size: Int, steps: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for _ in 0..<steps {
        var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
        for i in 0..<size {
            for j in 0..<size {
                var neighbors = 0
                for dx in [-1, 0, 1] {
                    for dy in [-1, 0, 1] {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size]
                    }
                }
                neighbors -= grid[i][j]
                newGrid[i][j] = neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
            }
        }
        grid = newGrid
    }
    return grid
}

cellularAutomata(size: 10, steps: 5)