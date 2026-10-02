import Foundation

func initializeGrid(size: Int) -> [[Int]] {
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    return grid
}

func updateGrid(grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            var neighbors = 0
            for di in -1...1 {
                for dj in -1...1 {
                    if (di, dj) != (0, 0) {
                        neighbors += grid[(i + di + size) % size][(j + dj + size) % size]
                    }
                }
            }
            newGrid[i][j] = neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
        }
    }
    return newGrid
}

func simulate(steps: Int, size: Int) -> [[Int]] {
    var grid = initializeGrid(size: size)
    for _ in 0..<steps {
        grid = updateGrid(grid: grid)
    }
    return grid
}

func main() {
    let steps = 10
    let size = 5
    let result = simulate(steps: steps, size: size)
    for row in result {
        print(row.map { String($0) }.joined(separator: " "))
    }
}

main()