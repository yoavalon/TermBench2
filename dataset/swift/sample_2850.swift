import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let shape = (grid.count, grid[0].count)
    var newGrid = Array(repeating: Array(repeating: 0, count: shape.1), count: shape.0)
    for i in 0..<shape.0 {
        for j in 0..<shape.1 {
            var neighbors = 0
            for ni in max(0, i - 1)...min(shape.0 - 1, i + 1) {
                for nj in max(0, j - 1)...min(shape.1 - 1, j + 1) {
                    neighbors += grid[ni][nj]
                }
            }
            neighbors -= grid[i][j]
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
    let size = 100
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    while true {
        grid = updateGrid(grid)
    }
}

simulate()