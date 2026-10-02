swift
import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = (max(i - 1, 0)...min(i + 1, rows - 1)).flatMap { i in
                (max(j - 1, 0)...min(j + 1, cols - 1)).compactMap { j in
                    grid[i][j]
                }
            }.reduce(0, +) - grid[i][j]
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

func main() {
    let size = 10
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

main()