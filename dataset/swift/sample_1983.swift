func updateGrid(grid: [[Double]]) -> [[Double]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            if i > 0 && j > 0 && i < rows - 1 && j < cols - 1 {
                newGrid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            } else {
                newGrid[i][j] = grid[i][j]
            }
        }
    }
    return newGrid
}

func simulate(n: Int, size: Int) -> [[Double]] {
    var grid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Double(i == size / 2 && j == size / 2 ? 1 : 0)
        }
    }
    for _ in 0..<n {
        grid = updateGrid(grid: grid)
    }
    return grid
}

func main() {
    let result = simulate(n: 10, size: 5)
    for row in result {
        print(row)
    }
}

main()