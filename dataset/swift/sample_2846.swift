import Foundation

func generateGrid(size: Int) -> [[Int]] {
    return (0..<size).map { _ in (0..<size).map { _ in Int.random(in: 0...1) } }
}

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for dx in [-1, 0, 1] {
                for dy in [-1, 0, 1] {
                    if (dx, dy) != (0, 0) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size]
                    }
                }
            }
            if (grid[i][j] == 1 && neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1
            }
        }
    }
    return newGrid
}

func main() {
    let size = 10
    var grid = generateGrid(size: size)
    while true {
        grid = updateGrid(grid)
    }
}

main()