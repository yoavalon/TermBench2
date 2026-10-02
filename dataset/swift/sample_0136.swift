import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: 0, count: size), count: size)
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = grid.map { $0.map { $0 } }
    
    for i in 0..<rows {
        for j in 0..<cols {
            let neighbors = (max(0, i - 1)...min(rows - 1, i + 1)).flatMap { i in
                (max(0, j - 1)...min(cols - 1, j + 1)).map { j in
                    grid[i][j]
                }
            }.reduce(0, +) - grid[i][j]
            
            if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            } else if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                newGrid[i][j] = 0
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 50
    let iterations = 100
    var grid = initializeGrid(size: gridSize)
    
    for _ in 0..<iterations {
        grid = updateGrid(grid: grid)
    }
    
    for row in grid {
        print(row)
    }
}

main()