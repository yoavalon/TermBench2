import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = grid.map { $0.map { $0 } }
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = grid[max(0, i - 1)...min(rows - 1, i + 1)].flatMap { $0[max(0, j - 1)...min(cols - 1, j + 1)] }.reduce(0, +) - grid[i][j]
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let size = 50
    var grid = (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
    while true {
        grid = updateGrid(grid)
    }
}

main()