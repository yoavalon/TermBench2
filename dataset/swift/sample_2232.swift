import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    var grid = [[Int]](repeating: [Int](repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    return grid
}

func evolve(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var nextGrid = [[Int]](repeating: [Int](repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    if di == 0 && dj == 0 {
                        continue
                    }
                    let ni = (i + di + size) % size
                    let nj = (j + dj + size) % size
                    neighbors += grid[ni][nj]
                }
            }
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                nextGrid[i][j] = 0
            } else if grid[i][j] == 0 && neighbors == 3 {
                nextGrid[i][j] = 1
            } else {
                nextGrid[i][j] = grid[i][j]
            }
        }
    }
    return nextGrid
}

func main() {
    let gridSize = 100
    var grid = initializeGrid(size: gridSize)
    while true {
        grid = evolve(grid: grid)
    }
}

main()