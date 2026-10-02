import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = Array(repeating: Array(repeating: 0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    if di == 0 && dj == 0 {
                        continue
                    }
                    let ni = i + di
                    let nj = j + dj
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            newGrid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j] == 1)) ? 1 : 0
        }
    }
    return newGrid
}

func main() {
    var grid = Array(repeating: Array(repeating: 0, count: 50), count: 50)
    grid[25][25] = 1
    while true {
        grid = updateGrid(grid)
    }
}

main()