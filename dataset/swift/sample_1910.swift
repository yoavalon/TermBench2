import Foundation

func updateGrid(grid: [[Float]]) -> [[Float]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 1..<rows - 1 {
        for j in 1..<cols - 1 {
            var sum: Float = 0
            for x in i - 1...i + 1 {
                for y in j - 1...j + 1 {
                    sum += grid[x][y]
                }
            }
            newGrid[i][j] = sum - grid[i][j]
        }
    }
    return newGrid
}

func simulateFlow(iterations: Int) -> [[Float]] {
    var grid = Array(repeating: Array(repeating: 0.0, count: 10), count: 10)
    for i in 0..<10 {
        for j in 0..<10 {
            grid[i][j] = Float.random(in: 0.0...1.0)
        }
    }
    for _ in 0..<iterations {
        grid = updateGrid(grid: grid)
    }
    return grid
}

func main() {
    let result = simulateFlow(iterations: 100)
    for row in result {
        print(row)
    }
}

main()