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
            if grid[i][j] == 1 {
                newGrid[i][j] = (2...3).contains(neighbors) ? 1 : 0
            } else {
                newGrid[i][j] = neighbors == 3 ? 1 : 0
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 10
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    grid[gridSize / 2][gridSize / 2] = 1
    let steps = 50
    for _ in 0..<steps {
        grid = updateGrid(grid)
    }
    for row in grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()