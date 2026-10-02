func initializeGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[size / 2][size / 2] = 1
    return grid
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for i in 0..<grid.count {
        for j in 0..<grid[i].count {
            var neighbors = 0
            for x in i - 1...i + 1 {
                for y in j - 1...j + 1 {
                    if x >= 0 && x < grid.count && y >= 0 && y < grid[i].count && (x != i || y != j) {
                        neighbors += grid[x][y]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    let size = 50
    var grid = initializeGrid(size: size)
    while true {
        grid = updateGrid(grid: grid)
    }
}

main()