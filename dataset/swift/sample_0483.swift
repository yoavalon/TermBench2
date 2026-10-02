func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
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
            newGrid[i][j] = grid[i][j] != 0 ? (neighbors >= 2 && neighbors <= 3 ? 1 : 0) : (neighbors == 3 ? 1 : 0)
        }
    }
    return newGrid
}

func simulate(_ grid: [[Int]]) {
    while true {
        let newGrid = updateGrid(grid)
    }
}

func main() {
    let initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
    simulate(initialGrid)
}

main()