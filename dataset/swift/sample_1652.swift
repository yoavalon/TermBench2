func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for x in (i - 1)...(i + 1) {
                for y in (j - 1)...(j + 1) {
                    if x >= 0 && x < rows && y >= 0 && y < cols && (x, y) != (i, j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 || (neighbors == 2 && grid[i][j] == 1) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(_ grid: inout [[Int]]) {
    while true {
        grid = updateGrid(grid)
    }
}

func main() {
    var initialGrid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ]
    simulate(&initialGrid)
}

main()