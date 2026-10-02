func updateGrid(_ grid: [[Double]]) -> [[Double]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var total = 0.0
            for di in [-1, 0, 1] {
                for dj in [-1, 0, 1] {
                    let ni = i + di
                    let nj = j + dj
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
                        total += grid[ni][nj]
                    }
                }
            }
            newGrid[i][j] = total / 9.0
        }
    }
    return newGrid
}

func simulate() {
    var grid = [[Double]]()
    for i in 0..<10 {
        grid.append((0..<10).map { Double(i + $0) })
    }
    while true {
        grid = updateGrid(grid)
    }
}

simulate()