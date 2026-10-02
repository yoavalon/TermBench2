import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    return Array(repeating: Array(repeating: 0, count: size), count: size)
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let rows = grid.count
    let cols = grid[0].count
    var newGrid = grid

    for i in 1..<rows - 1 {
        for j in 1..<cols - 1 {
            let neighbors = (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                              grid[i][j - 1] + grid[i][j + 1] +
                              grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1])
            if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) {
                newGrid[i][j] = 1
            } else {
                newGrid[i][j] = 0
            }
        }
    }
    return newGrid
}

func main() {
    let size = 50
    var grid = initializeGrid(size: size)
    while true {
        grid = updateGrid(grid: grid)
    }
}

main()