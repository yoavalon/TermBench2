func cellularAutomata(rows: Int, cols: Int, steps: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for _ in 0..<steps {
        var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
        for i in 0..<rows {
            for j in 0..<cols {
                var neighbors = 0
                for dx in [-1, 0, 1] {
                    for dy in [-1, 0, 1] {
                        if dx != 0 || dy != 0 {
                            neighbors += grid[(i + dx + rows) % rows][(j + dy + cols) % cols]
                        }
                    }
                }
                newGrid[i][j] = neighbors == 3 ? 1 : grid[i][j]
            }
        }
        grid = newGrid
    }
    return grid
}

func main() {
    while true {
        cellularAutomata(rows: 10, cols: 10, steps: 100)
    }
}

main()