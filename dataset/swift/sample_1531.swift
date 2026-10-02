import Foundation

func cellularAutomata(width: Int, height: Int) {
    var grid = Array(repeating: Array(repeating: 0, count: width), count: height)
    while true {
        var newGrid = grid
        for i in 1..<height - 1 {
            for j in 1..<width - 1 {
                let neighbors = (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                               grid[i][j - 1] + grid[i][j + 1] +
                               grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1])
                if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0
                } else if grid[i][j] == 0 && neighbors == 3 {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }
}

cellularAutomata(width: 50, height: 50)