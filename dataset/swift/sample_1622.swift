import Foundation

func updateGrid(_ grid: [[Int]]) -> [[Int]] {
    let size = grid.count
    var newGrid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            let neighbors = [
                grid[(i - 1 + size) % size][(j - 1 + size) % size],
                grid[(i - 1 + size) % size][j],
                grid[(i - 1 + size) % size][(j + 1) % size],
                grid[i][(j - 1 + size) % size],
                grid[i][(j + 1) % size],
                grid[(i + 1) % size][(j - 1 + size) % size],
                grid[(i + 1) % size][j],
                grid[(i + 1) % size][(j + 1) % size]
            ]
            let liveNeighbors = neighbors.reduce(0, +)
            if grid[i][j] == 1 {
                newGrid[i][j] = liveNeighbors == 2 || liveNeighbors == 3 ? 1 : 0
            } else {
                newGrid[i][j] = liveNeighbors == 3 ? 1 : 0
            }
        }
    }
    return newGrid
}

func main() {
    let size = 10
    var grid = Array(repeating: Array(repeating: 0, count: size), count: size)
    for i in 0..<size {
        for j in 0..<size {
            grid[i][j] = Int.random(in: 0...1)
        }
    }
    while true {
        grid = updateGrid(grid)
        for row in grid {
            print(row.map { String($0) }.joined(separator: " "))
        }
        print()
    }
}

main()