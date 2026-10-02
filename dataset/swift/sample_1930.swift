import Foundation

func updateGrid(_ grid: [[Double]], _ precision: Int) -> [[Double]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: size), count: size)
    for i in 1..<size - 1 {
        for j in 1..<size - 1 {
            let avg = (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                      grid[i][j - 1] + grid[i][j] + grid[i][j + 1] +
                      grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]) / 9.0
            newGrid[i][j] = (avg * pow(10.0, Double(precision))).rounded() / pow(10.0, Double(precision))
        }
    }
    return newGrid
}

func runSimulation(_ steps: Int, _ precision: Int) -> [[Double]] {
    let gridSize = 10
    var grid = Array(repeating: Array(repeating: Double.random(in: 0...1), count: gridSize), count: gridSize)
    for _ in 0..<steps {
        grid = updateGrid(grid, precision)
    }
    return grid
}

func main() {
    let steps = 50
    let precision = 3
    let result = runSimulation(steps, precision)
    for row in result {
        print(row.map { String(format: "%.\(precision)f", $0) }.joined(separator: " "))
    }
}

main()