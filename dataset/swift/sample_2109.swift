import Foundation

func simulate() {
    var grid = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)
    
    while true {
        var newGrid = grid
        
        for i in 1..<99 {
            for j in 1..<99 {
                newGrid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1])
            }
        }
        
        grid = newGrid
    }
}

simulate()