import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = (max(0, i - 1)...min(rows - 1, i + 1)).flatMap { row in
                (max(0, j - 1)...min(cols - 1, j + 1)).compactMap { col in
                    (row != i || col != j) ? grid[row][col] : nil
                }
            }.reduce(0, +)
            if grid[i][j] == 1 && (neighbors == 3 || neighbors == 4) {
                newGrid[i][j] = 1
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 50
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    for i in 0..<gridSize {
        for j in 0..<gridSize {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    while true {
        grid = updateGrid(grid)
    }
}

main()