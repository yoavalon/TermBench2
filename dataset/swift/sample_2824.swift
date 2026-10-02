func initGrid(rows: Int, cols: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    grid[rows / 2][cols / 2] = 1
    return grid
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].compactMap { x, y in
                (0 <= x && x < rows && 0 <= y && y < cols) ? grid[x][y] : nil
            }.reduce(0, +)
            newGrid[i][j] = neighbors == 1 ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    var grid = initGrid(rows: 10, cols: 10)
    while true {
        grid = updateGrid(grid)
    }
}

main()