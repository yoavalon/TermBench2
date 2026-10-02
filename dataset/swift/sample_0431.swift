import Foundation

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var aliveNeighbors = 0
            for ni in max(0, i-1)...min(rows-1, i+1) {
                for nj in max(0, j-1)...min(cols-1, j+1) {
                    if ni == i && nj == j {
                        continue
                    }
                    aliveNeighbors += grid[ni][nj]
                }
            }
            if grid[i][j] == 1 && (aliveNeighbors < 2 || aliveNeighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && aliveNeighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate(gridSize: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 0..<gridSize {
        for j in 0..<gridSize {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    while true {
        grid = updateGrid(grid: grid)
        print(grid.map { $0.map { String($0) }.joined(separator: " ") }.joined(separator: "\n"))
    }
}

simulate(gridSize: 10)