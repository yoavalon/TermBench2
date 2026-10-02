func initializeGrid(size: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: 0, count: size), count: size)
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    var newGrid = grid.map { $0 }
    for i in 0..<grid.count {
        for j in 0..<grid[i].count {
            var neighbors = 0
            for x in -1...1 {
                for y in -1...1 {
                    if x == 0 && y == 0 {
                        continue
                    }
                    let ni = i + x
                    let nj = j + y
                    if ni >= 0 && ni < grid.count && nj >= 0 && nj < grid[i].count {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    let gridSize = 10
    var grid = initializeGrid(size: gridSize)
    while true {
        grid = updateGrid(grid)
    }
}

main()