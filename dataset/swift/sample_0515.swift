import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    return (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for x in [-1, 0, 1] {
                for y in [-1, 0, 1] {
                    if x == 0 && y == 0 {
                        continue
                    }
                    let ni = (i + x + size) % size
                    let nj = (j + y + size) % size
                    neighbors += grid[ni][nj]
                }
            }
            if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) {
                newGrid[i][j] = 1
            } else if grid[i][j] == 0 && neighbors == 3 {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let gridSize = 50
    var grid = initializeGrid(size: gridSize)
    while true {
        grid = updateGrid(grid: grid)
    }
}

main()