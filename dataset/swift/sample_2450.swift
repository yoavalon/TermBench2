func simulateCells(rows: Int, cols: Int, steps: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for _ in 0..<steps {
        var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
        for i in 0..<rows {
            for j in 0..<cols {
                var neighbors = 0
                for x in max(0, i - 1)...min(rows - 1, i + 1) {
                    for y in max(0, j - 1)...min(cols - 1, j + 1) {
                        if (x, y) != (i, j) {
                            neighbors += grid[x][y]
                        }
                    }
                }
                if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }
    return grid
}

simulateCells(rows: 10, cols: 10, steps: 5)