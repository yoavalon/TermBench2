import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = (max(0, i - 1)...min(rows - 1, i + 1)).flatMap { row in
                (max(0, j - 1)...min(cols - 1, j + 1)).map { col in
                    grid[row][col]
                }
            }.filter { $0 == 1 }.count - grid[i][j]
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    newGrid[i][j] = 0
                } else {
                    newGrid[i][j] = 1
                }
            } else if neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let size = 50
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