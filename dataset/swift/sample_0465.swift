func initializeGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[size / 2][size / 2] = 1
    return grid
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for x in max(0, i - 1)...min(size - 1, i + 1) {
                for y in max(0, j - 1)...min(size - 1, j + 1) {
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
    return newGrid
}

func main() {
    let gridSize = 10
    var grid = initializeGrid(size: gridSize)
    while true {
        grid = updateGrid(grid: grid)
    }
}

main()