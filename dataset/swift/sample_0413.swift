func initializeGrid(rows: Int, cols: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: 0, count: cols), count: rows)
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for i in 0..<grid.count {
        for j in 0..<grid[0].count {
            var neighbors = 0
            for x in i - 1...i + 1 {
                for y in j - 1...j + 1 {
                    if x >= 0 && x < grid.count && y >= 0 && y < grid[0].count && (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 ? 1 : neighbors < 2 || neighbors > 3 ? 0 : grid[i][j]
        }
    }
    return newGrid
}

func main() {
    let rows = 50
    let cols = 50
    var grid = initializeGrid(rows: rows, cols: cols)
    while true {
        grid = updateGrid(grid)
    }
}

main()