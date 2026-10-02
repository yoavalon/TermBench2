import Foundation

func updateState(_ grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = grid.map { $0.map { $0 } }
    
    for i in 0..<rows {
        for j in 0..<cols {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    let ni = i + di
                    let nj = j + dj
                    if ni >= 0 && ni < rows && nj >= 0 && nj < cols && !(di == 0 && dj == 0) {
                        neighbors += grid[ni][nj]
                    }
                }
            }
            if grid[i][j] == 1 {
                if neighbors < 2 || neighbors > 3 {
                    newGrid[i][j] = 0
                }
            } else if neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let size = 100
    var grid = (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
    while true {
        grid = updateState(grid)
    }
}

main()