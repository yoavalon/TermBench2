import Foundation

func simulate() {
    let gridSize = 30
    var grid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
    while true {
        var newGrid = Array(repeating: Array(repeating: 0, count: gridSize), count: gridSize)
        for i in 0..<gridSize {
            for j in 0..<gridSize {
                var neighbors = 0
                for x in [-1, 0, 1] {
                    for y in [-1, 0, 1] {
                        if (x, y) != (0, 0) {
                            neighbors += grid[(i + x + gridSize) % gridSize][(j + y + gridSize) % gridSize]
                        }
                    }
                }
                if (grid[i][j] == 1 && neighbors >= 2 && neighbors <= 3) || (grid[i][j] == 0 && neighbors == 3) {
                    newGrid[i][j] = 1
                }
            }
        }
        grid = newGrid
    }
}

simulate()