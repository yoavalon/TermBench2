import Foundation

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let gridSize = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 1..<gridSize - 1 {
        for j in 1..<gridSize - 1 {
            var neighbors = 0
            for ni in i - 1...i + 1 {
                for nj in j - 1...j + 1 {
                    if ni == i && nj == j { continue }
                    neighbors += grid[ni][nj]
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            } else {
                newGrid[i][j] = grid[i][j]
            }
        }
    }
    return newGrid
}

func simulate() {
    let gridSize = 50
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 0..<gridSize {
        for j in 0..<gridSize {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    while true {
        grid = updateGrid(grid: grid)
    }
}

simulate()