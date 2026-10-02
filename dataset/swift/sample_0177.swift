import Foundation

func initGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    grid[size / 2][size / 2] = 1
    return grid
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = grid.map { $0.map { $0 } }
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    if di == 0 && dj == 0 { continue }
                    let ni = max(0, min(size - 1, i + di))
                    let nj = max(0, min(size - 1, j + dj))
                    neighbors += grid[ni][nj]
                }
            }
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
    let size = 10
    var grid = initGrid(size: size)
    let steps = 50
    for _ in 0..<steps {
        grid = updateGrid(grid: grid)
    }
    for row in grid {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()