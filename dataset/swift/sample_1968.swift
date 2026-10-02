func updateGrid(_ grid: [[Double]]) -> [[Double]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 1..<rows - 1 {
        for j in 1..<cols - 1 {
            let avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
            newGrid[i][j] = (grid[i][j] + avg) / 2.0
        }
    }
    return newGrid
}

func simulate(_ grid: [[Double]], steps: Int) -> [[Double]] {
    var currentGrid = grid
    for _ in 0..<steps {
        currentGrid = updateGrid(currentGrid)
    }
    return currentGrid
}

func main() {
    let gridSize = 10
    let steps = 5
    var grid = Array(repeating: Array(repeating: 0.0, count: gridSize), count: gridSize)
    grid[gridSize / 2][gridSize / 2] = 1.0
    let result = simulate(grid, steps: steps)
    for row in result {
        print(row.map { String(format: "%.2f", $0) }.joined(separator: " "))
    }
}

main()