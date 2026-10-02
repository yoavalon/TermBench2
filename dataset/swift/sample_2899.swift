import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for ni in max(0, i - 1)...min(rows - 1, i + 1) {
                for nj in max(0, j - 1)...min(cols - 1, j + 1) {
                    neighbors += grid[ni][nj]
                }
            }
            neighbors -= grid[i][j]
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func simulate() {
    var grid = Array(repeating: Array(repeating: 0, count: 10), count: 10)
    for i in 0..<10 {
        for j in 0..<10 {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    
    while true {
        grid = updateGrid(grid)
        print(grid.map { $0.map { String($0) }.joined(separator: " ") }.joined(separator: "\n") )
        if grid.allSatisfy({ $0.allSatisfy({ $0 == 0 }) }) {
            break
        }
    }
}

simulate()