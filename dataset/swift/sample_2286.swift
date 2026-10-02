import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let gridSize = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 1..<gridSize - 1 {
        for j in 1..<gridSize - 1 {
            let neighbors = (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                             grid[i][j - 1] + grid[i][j + 1] +
                             grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1])
            if grid[i][j] == 1 {
                newGrid[i][j] = neighbors == 2 || neighbors == 3 ? 1 : 0
            } else {
                newGrid[i][j] = neighbors == 3 ? 1 : 0
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 50
    var grid = (0..<gridSize).map { _ in
        (0..<gridSize).map { _ in Int.random(in: 0...1) }
    }
    while true {
        grid = updateGrid(grid)
    }
}

main()