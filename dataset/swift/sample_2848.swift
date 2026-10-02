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
            let neighbors = (i - 1...i + 1).flatMap { x in (j - 1...j + 1).compactMap { y in
                guard x >= 0, x < size, y >= 0, y < size, (x, y) != (i, j) else { return nil }
                return grid[x][y]
            }).reduce(0, +)
            newGrid[i][j] = neighbors == 3 ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    let size = 10
    var grid = initializeGrid(size: size)
    while true {
        grid = updateGrid(grid: grid)
    }
}

main()